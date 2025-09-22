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

