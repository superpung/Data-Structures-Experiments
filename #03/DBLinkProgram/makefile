CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


DBLPro: main.cpp DBLinkList.o
	$(CC) main.cpp DBLinkList.o -o DBLProgram

DBLinkList.o: DBLinkList.h DBLinkList.cpp
	$(CC) -c DBLinkList.h DBLinkList.cpp

clean:
	rm *.o *.gch DBLProgram
