// velha.hpp - Interface do verificador do jogo da velha
// Representação: 0 = vazio, 1 = X, 2 = O
// Retornos:
//   1  -> X venceu
//   2  -> O venceu
//   0  -> Empate (tabuleiro cheio sem vencedor)
//  -1  -> Jogo indefinido (ainda pode evoluir)
//  -2  -> Jogo impossível (contagem inválida ou dois vencedores)

#ifndef VELHA_HPP
#define VELHA_HPP

// Códigos de estado (expostos para clareza e eventual reuso externo)
constexpr int VELHA_X_VENCE    = 1;
constexpr int VELHA_O_VENCE    = 2;
constexpr int VELHA_EMPATE     = 0;
constexpr int VELHA_INDEFINIDO = -1;
constexpr int VELHA_IMPOSSIVEL = -2;

int verificaVelha(int tabuleiro[3][3]);

// Helpers internos foram encapsulados no arquivo de implementação (velha.cpp)
// para manter a API pública mínima e permitir refatorações internas sem quebrar usuários.

#endif // VELHA_HPP


