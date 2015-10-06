#	Programmer:	Sajant Anand			Course: CSC112 Anand
#	Assignment: Lab8					Date:	3/30/15
CC = g++
CFLAGS = -Wall -pedantic -g
lab8: lab8.o words.o stemming.o
	$(CC) -o lab8 lab8.o words.o stemming.o
lab8.o: lab8.cpp words.h stemming.h
	$(CC) $(CFLAGS) -c lab8.cpp
words.o: words.cpp words.h
	$(CC) $(CFLAGS) -c words.cpp
stemming.o: stemming.cpp stemming.h words.h
	$(CC) $(CFLAGS) -c stemming.cpp

clean:
	\rm -f *.o lab8