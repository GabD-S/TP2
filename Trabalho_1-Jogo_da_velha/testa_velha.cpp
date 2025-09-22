// testa_velha.cpp - Fase RED inicial
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.hpp"

TEST_CASE("Tabuleiro vazio deve retornar -1 (indefinido)", "[velha][red]") {
    int tabuleiro[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    REQUIRE(verificaVelha(tabuleiro) == -1);
}

TEST_CASE("Jogo ainda indefinido com algumas jogadas sem vencedor", "[velha][red]") {
    // Situação: algumas jogadas, ninguém venceu, ainda há espaços livres
    int tabuleiro[3][3] = {
        {1, 0, 2},
        {0, 2, 0},
        {0, 1, 0}
    };
    REQUIRE(verificaVelha(tabuleiro) == -1);
}

TEST_CASE("Jogo indefinido com apenas primeira jogada de X", "[velha][indefinido]") {
    int tabuleiro[3][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificaVelha(tabuleiro) == -1);
}

TEST_CASE("Jogo indefinido com abertura equilibrada", "[velha][indefinido]") {
    int tabuleiro[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 0}
    };
    REQUIRE(verificaVelha(tabuleiro) == -1);
}

TEST_CASE("Jogo indefinido quase cheio sem vitória", "[velha][indefinido]") {
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {2, 1, 0},
        {2, 1, 2}
    };
    // Ainda há um espaço vazio (1,2) e nenhuma linha/coluna/diagonal vencedora
    REQUIRE(verificaVelha(tabuleiro) == -1);
}

// =============================
// RED: Casos de jogo impossível
// =============================

TEST_CASE("Impossível: valor fora do domínio", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {3, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }; // 3 é inválido
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Impossível: O começa antes de X", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {2, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }; // O jogou primeiro
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Impossível: diferença de contagem exagerada", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {1, 1, 0},
        {0, 0, 0}
    }; // X=5, O=0 -> inválido
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Impossível: dois vencedores simultâneos", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {1, 1, 1}, // X vence na linha 0
        {2, 2, 2}, // O vence na linha 1
        {0, 0, 0}
    };
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Impossível: vitória de X com contagem incoerente", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {2, 2, 0},
        {2, 0, 0}
    }; // X=3, O=4 (O > X) e X supostamente venceu -> incoerente
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Impossível: vitória de O com contagem incoerente", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {2, 2, 2},
        {1, 0, 0},
        {0, 0, 0}
    }; // O venceu mas contagem X=1 O=3 -> deveria ser X=O (incoerente)
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Impossível: todos X", "[velha][impossivel][red]") {
    int tabuleiro[3][3] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    }; // X=9 O=0 -> impossível
    REQUIRE(verificaVelha(tabuleiro) == -2);
}

TEST_CASE("Regressão: todos cenários atuais", "[velha][regressao][suite]") {
    struct Caso {
        int b[3][3];
        int esperado;
        const char* descricao;
    };
    std::vector<Caso> casos = {
        // Indefinidos (-1)
        {{{0,0,0},{0,0,0},{0,0,0}}, -1, "vazio"},
        {{{1,0,0},{0,0,0},{0,0,0}}, -1, "primeira jogada X"},
        {{{1,2,0},{0,0,0},{0,0,0}}, -1, "abertura X e O"},
        {{{1,2,1},{2,0,0},{0,0,0}}, -1, "meio de jogo"},
        {{{1,2,1},{2,1,0},{2,1,2}}, -1, "quase cheio sem vitória"},
        // Impossíveis (-2)
        {{{3,0,0},{0,0,0},{0,0,0}}, -2, "valor fora do domínio"},
        {{{2,0,0},{0,0,0},{0,0,0}}, -2, "O começa"},
        {{{1,1,1},{1,1,0},{0,0,0}}, -2, "X muito à frente"},
        {{{1,1,1},{2,2,2},{0,0,0}}, -2, "dois vencedores"},
        {{{1,1,1},{2,2,0},{2,0,0}}, -2, "vitória X contagem incoerente"},
        {{{2,2,2},{1,0,0},{0,0,0}}, -2, "vitória O contagem incoerente"},
        {{{1,1,1},{1,1,1},{1,1,1}}, -2, "todos X"}
    };

    for (const auto &c : casos) {
        CAPTURE(c.descricao);
        int tab[3][3];
        for (int i=0;i<3;++i) for (int j=0;j<3;++j) tab[i][j]=c.b[i][j];
        REQUIRE(verificaVelha(tab) == c.esperado);
    }
}

// ===== Próxima fase: vitórias =====
// RED 1: vitória simples de X (linha 0) deve retornar 1
TEST_CASE("Vitória de X em linha superior", "[velha][vitoria][red]") {
    int tabuleiro[3][3] = {
        {1,1,1},
        {2,2,0},
        {0,0,0}
    }; // X venceu na primeira linha, contagens: X=3, O=2 (estado legal)
    REQUIRE(verificaVelha(tabuleiro) == 1);
}

