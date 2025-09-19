// velha.cpp - Implementação GREEN mínima para caso 'jogo indefinido (tabuleiro vazio)'
#include "velha.hpp"

int verificaVelha(int tabuleiro[3][3]) {
	// Verifica se todas as posições são 0 (tabuleiro vazio)
	bool vazio = true;
	for (int i = 0; i < 3 && vazio; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (tabuleiro[i][j] != 0) {
				vazio = false;
				break;
			}
		}
	}
	if (vazio) {
		return -1; // jogo indefinido (nenhuma jogada)
	}

	// Demais regras (vitória, empate, impossível) serão implementadas em ciclos futuros.
	return 0; // placeholder para outros estados ainda não tratados
}


