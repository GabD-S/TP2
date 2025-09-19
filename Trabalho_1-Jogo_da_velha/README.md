# Jogo da Velha com TDD — Trabalho Prático 2

## Objetivo

Desenvolver uma função `verificaVelha()` para analisar o estado de um jogo da velha, utilizando a metodologia TDD (Test-Driven Development) e diversas ferramentas de qualidade de software. O projeto deve ser modular, com interface, implementação e testes separados, e seguir rigorosamente o ciclo RED-GREEN-REFACTOR do TDD, registrando cada etapa em commits no Git.

## Estrutura do Projeto

- `velha.hpp` — Interface da função
- `velha.cpp` — Implementação da função
- `testa_velha.cpp` — Testes unitários (usando Catch2)
- `catch.hpp` — Framework de testes
- `cpplint.py` — Verificador de estilo
- `Makefile` — Sistema de build e automação de verificações
- `.gitignore` — Arquivos a serem ignorados pelo Git
- `leiame.txt` — Instruções de compilação e uso

## Metodologia

O desenvolvimento deve seguir o ciclo TDD:
1.  **RED:** Escrever um teste que falha.
2.  **GREEN:** Implementar o código mínimo para passar o teste.
3.  **REFACTOR:** Refatorar o código mantendo todos os testes passando.

Cada etapa deve ser registrada com um commit específico e descritivo no Git.

## Ferramentas de Qualidade

- **Catch2:** Framework de testes unitários.
- **gcov:** Cobertura de código (mínimo 80%).
- **cppcheck:** Análise estática (zero warnings/erros).
- **Valgrind:** Verificação de vazamentos de memória (zero leaks).
- **cpplint:** Verificação de estilo (Google C++ Style Guide).
- **GDB:** Depuração.
- **Git:** Controle de versão (histórico TDD obrigatório).

## Compilação e Execução

- Compilar: `make`
- Executar testes: `make test`
- Verificar cobertura: `make coverage`
- Análise estática: `make cppcheck`
- Verificação de estilo: `make cpplint`
- Verificação de memória: `make valgrind`
- Limpar arquivos gerados: `make clean`
- Verificação completa: `make all-checks`

## Entrega

- Compactar todos os arquivos obrigatórios, incluindo o diretório `.git`, em um arquivo nomeado conforme as instruções do edital.
- Certificar-se de que todos os testes passam, a cobertura está adequada e não há erros de estilo, análise estática ou vazamentos de memória.

## Observações Finais

- O histórico de commits do Git será o principal critério de avaliação, devendo evidenciar o ciclo TDD.
- Siga a ordem sugerida de testes e implemente cada caso de forma incremental.
- Consulte o arquivo `leiame.txt` para instruções detalhadas de uso.
