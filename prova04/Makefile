GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := supermercado

all: $(PROGRAM)

$(PROGRAM): main.o Market.o Product.o Customer.o App.o utils.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Market.o Product.o Customer.o App.o utils.o

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Market.o: src/Market.cpp include/Market.h
	$(GCC) $(FLAGS) -c src/Market.cpp

Product.o: src/Product.cpp include/Product.h
	$(GCC) $(FLAGS) -c src/Product.cpp

Customer.o: src/Customer.cpp include/Customer.h
	$(GCC) $(FLAGS) -c src/Customer.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(FLAGS) -c src/App.cpp

utils.o: src/utils.cpp include/utils.h
	$(GCC) $(FLAGS) -c src/utils.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)

.PHONY: all clean
