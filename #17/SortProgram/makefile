CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


MySortProgram: main.cpp MySort.o
	$(CC) main.cpp MySort.o -o MySortProgram

MySort.o: MySort.h MySort.cpp
	$(CC) -c MySort.h MySort.cpp

clean:
	rm *.o *.gch MySortProgram
