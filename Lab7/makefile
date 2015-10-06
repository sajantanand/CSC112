#	Programmer:	Sajant Anand			Course: CSC112 Anand
#	Assignment: Lab8					Date:	3/26/15
CC = g++
CFLAGS = -Wall -pedantic -g
lab7: lab7.o words.o
	$(CC) -o lab7 lab7.o words.o
lab7.o: lab7.cpp words.h
	$(CC) $(CFLAGS) -c lab7.cpp
words.o: words.cpp words.h
	$(CC) $(CFLAGS) -c words.cpp

clean:
	\rm -f *.o lab7