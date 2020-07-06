GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := main

all: $(PROGRAM)

$(PROGRAM): main.o Conta.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Conta.o

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(FLAGS) -c src/Conta.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)

.PHONY: all clean
