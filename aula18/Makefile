GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := main

all: $(PROGRAM)

$(PROGRAM): main.o Fila.o Conta.o Cliente.o ClientePF.o ClientePJ.o Agencia.o Funcionario.o Gerente.o Caixa.o Seguranca.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Fila.o Conta.o Cliente.o ClientePF.o ClientePJ.o Agencia.o Funcionario.o Gerente.o Caixa.o Seguranca.o

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(FLAGS) -c src/Cliente.cpp

ClientePF.o: src/ClientePF.cpp include/ClientePF.h
	$(GCC) $(FLAGS) -c src/ClientePF.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.h
	$(GCC) $(FLAGS) -c src/ClientePJ.cpp

Agencia.o: src/Agencia.cpp include/Agencia.h
	$(GCC) $(FLAGS) -c src/Agencia.cpp

Fila.o: src/Fila.cpp include/Fila.h
	$(GCC) $(FLAGS) -c src/Fila.cpp

Funcionario.o: src/Funcionario.cpp include/Funcionario.h
	$(GCC) $(FLAGS) -c src/Funcionario.cpp

Gerente.o: src/Gerente.cpp include/Gerente.h
	$(GCC) $(FLAGS) -c src/Gerente.cpp

Caixa.o: src/Caixa.cpp include/Caixa.h
	$(GCC) $(FLAGS) -c src/Caixa.cpp

Seguranca.o: src/Seguranca.cpp include/Seguranca.h
	$(GCC) $(FLAGS) -c src/Seguranca.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)

.PHONY: all clean
