CC = g++
CFLAGS = -Wall -std=c++11

all: lista-seq

lista-seq: lista-seq.o main.o
	$(CC) $(CFLAGS) -o lista-seq lista-seq.o main.o

lista-seq.o: lista-seq.cpp lista-seq.h
	$(CC) $(CFLAGS) -c lista-seq.cpp

main.o: main.cpp lista-seq.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o lista-seq
