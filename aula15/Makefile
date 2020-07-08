GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := main

all: $(PROGRAM)

$(PROGRAM): main.o Conta.o Cliente.o Agencia.o Motor.o Carro.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Conta.o Cliente.o Agencia.o Motor.o Carro.o

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(FLAGS) -c src/Cliente.cpp

Agencia.o: src/Agencia.cpp include/Agencia.h
	$(GCC) $(FLAGS) -c src/Agencia.cpp

Motor.o: src/Motor.cpp include/Motor.h
	$(GCC) $(FLAGS) -c src/Motor.cpp

Carro.o: src/Carro.cpp include/Carro.h
	$(GCC) $(FLAGS) -c src/Carro.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)

.PHONY: all clean
