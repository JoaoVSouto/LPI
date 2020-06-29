GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAM := diary
TEST := run_test

all: $(PROGRAM) $(TEST)

$(PROGRAM): main.o Diary.o Date.o Time.o App.o Message.o utils.o
	$(GCC) $(FLAGS) -o $(PROGRAM) main.o Diary.o Date.o Time.o App.o Message.o utils.o

$(TEST): test.o Diary.o Date.o Time.o App.o Message.o utils.o
	$(GCC) $(FLAGS) -o $(TEST) main.o Diary.o Date.o Time.o App.o Message.o utils.o

test.o: test/main.cpp
	$(GCC) $(FLAGS) -c test/main.cpp

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(FLAGS) -c src/Time.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(FLAGS) -c src/App.cpp

Message.o: src/Message.cpp include/Message.h
	$(GCC) $(FLAGS) -c src/Message.cpp

utils.o: src/utils.cpp include/utils.h
	$(GCC) $(FLAGS) -c src/utils.cpp

clean:
	rm -f *.o

.PHONY: all clean
