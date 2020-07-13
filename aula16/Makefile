GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := company

all: $(PROGRAM)

$(PROGRAM): main.o Company.o Employee.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Company.o Employee.o

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Company.o: src/Company.cpp include/Company.h
	$(GCC) $(FLAGS) -c src/Company.cpp

Employee.o: src/Employee.cpp include/Employee.h
	$(GCC) $(FLAGS) -c src/Employee.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)

.PHONY: all clean
