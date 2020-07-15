GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := main

all: $(PROGRAM)

$(PROGRAM): main.o Fila.o Conta.o Cliente.o ClientePJ.o Agencia.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Fila.o Conta.o Cliente.o ClientePJ.o Agencia.o

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(FLAGS) -c src/Cliente.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.h
	$(GCC) $(FLAGS) -c src/ClientePJ.cpp

Agencia.o: src/Agencia.cpp include/Agencia.h
	$(GCC) $(FLAGS) -c src/Agencia.cpp

Fila.o: src/Fila.cpp include/Fila.h
	$(GCC) $(FLAGS) -c src/Fila.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)

.PHONY: all clean
