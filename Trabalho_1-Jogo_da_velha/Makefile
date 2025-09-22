#############################################################
# Makefile para Jogo da Velha (TDD)
# Uso:
#   make            -> compila binário
#   make test       -> executa testes
#   make coverage   -> gcov
#   make cppcheck   -> análise estática
#   make cpplint    -> estilo Google
#   make valgrind   -> checagem memória
#   make all-checks -> roda tudo
#   make clean      -> limpa
#############################################################

CXX       = g++
CXXFLAGS  = -std=c++11 -Wall -Wextra -g
COVFLAGS  = -fprofile-arcs -ftest-coverage
LDFLAGS   = -lgcov

SOURCES   = velha.cpp
OBJECTS   = $(SOURCES:.cpp=.o)
TEST_SRC  = testa_velha.cpp
EXEC      = testa_velha

.PHONY: all test coverage cppcheck cpplint valgrind debug all-checks clean

all: $(EXEC)

$(EXEC): $(OBJECTS) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(TEST_SRC) -o $(EXEC)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(EXEC)
	./$(EXEC)

cpplint:
	python3 cpplint.py --filter=-legal/copyright *.cpp *.hpp

cppcheck:
	cppcheck --enable=warning --std=c++11 --suppress=missingIncludeSystem .

coverage: clean
	$(CXX) $(CXXFLAGS) $(COVFLAGS) -c velha.cpp
	$(CXX) $(CXXFLAGS) $(COVFLAGS) velha.o $(TEST_SRC) -o $(EXEC) $(LDFLAGS)
	./$(EXEC)
	gcov $(SOURCES)
	@echo "Arquivos .gcov gerados:"
	@ls -1 *.gcov

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)

debug: $(EXEC)
	gdb ./$(EXEC)

all-checks: test cppcheck cpplint coverage valgrind
	@echo "=== Todas as verificações concluídas ==="

# Executa testes e grava saída completa em all_tests.txt
all-tests-log: $(EXEC)
	./$(EXEC) > all_tests.txt 2>&1 || true
	@echo "Saída dos testes registrada em all_tests.txt"

clean:
	rm -f *.o *.gcno *.gcda *.gcov $(EXEC) valgrind.rpt


