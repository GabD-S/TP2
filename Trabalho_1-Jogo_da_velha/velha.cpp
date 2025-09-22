// velha.cpp - Expansão: validações de estados impossíveis e indefinidos
#include "velha.hpp"

namespace velha_internal {
void contaJogadas(int tabuleiro[3][3], int &xCount, int &oCount, bool &temJogada) {
	xCount = 0; oCount = 0; temJogada = false;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int v = tabuleiro[i][j];
			if (v == 1) { ++xCount; temJogada = true; }
			else if (v == 2) { ++oCount; temJogada = true; }
			else if (v != 0) { // valor inválido fora do domínio
				// Tratar como impossível imediatamente via marcação especial
				xCount = -999; oCount = -999; return;
			}
		}
	}
}

bool venceuLinha(const int t[3][3], int p) {
	for (int i = 0; i < 3; ++i) {
		if (t[i][0] == p && t[i][1] == p && t[i][2] == p) return true;
	}
	return false;
}
bool venceuColuna(const int t[3][3], int p) {
	for (int j = 0; j < 3; ++j) {
		if (t[0][j] == p && t[1][j] == p && t[2][j] == p) return true;
	}
	return false;
}
bool venceuDiagonal(const int t[3][3], int p) {
	return (t[0][0] == p && t[1][1] == p && t[2][2] == p) ||
		   (t[0][2] == p && t[1][1] == p && t[2][0] == p);
}
bool venceu(const int t[3][3], int p) {
	return venceuLinha(t, p) || venceuColuna(t, p) || venceuDiagonal(t, p);
} // namespace velha_internal
}

int verificaVelha(int tabuleiro[3][3]) {
	// 1. Tabuleiro vazio => jogo indefinido
	bool vazio = true;
	for (int i = 0; i < 3 && vazio; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (tabuleiro[i][j] != 0) { vazio = false; break; }
		}
	}
	if (vazio) return -1;

	// 2. Contagem de jogadas e validação de domínio
	int xCount = 0, oCount = 0; bool temJogada = false;
	velha_internal::contaJogadas(tabuleiro, xCount, oCount, temJogada);
	if (xCount == -999) { // valor inválido detectado
		return -2; // impossível
	}

	// 3. Diferença de contagem inválida: X inicia, logo:
	//    xCount == oCount  OU  xCount == oCount + 1 é válido
	if (!(xCount == oCount || xCount == oCount + 1)) {
		return -2; // impossível
	}

	// 4. Verificar vencedores
	bool xVenceu = velha_internal::venceu(tabuleiro, 1);
	bool oVenceu = velha_internal::venceu(tabuleiro, 2);

	// 5. Dois vencedores simultâneos => impossível
	if (xVenceu && oVenceu) {
		return -2;
	}

	// 6. Coerência entre vitória e contagem
	//    - Se X venceu: xCount deve ser oCount + 1
	if (xVenceu && xCount != oCount + 1) {
		return -2;
	}
	//    - Se O venceu: xCount deve ser oCount (porque X sempre joga primeiro)
	if (oVenceu && xCount != oCount) {
		return -2;
	}

	// Ainda não decidimos retornar vitória/empate; isso virá em próximos ciclos.
	// Por enquanto, qualquer estado que não seja vazio ou impossível permanece como 0 (placeholder / indefinido provisório).
	return 0;
}


