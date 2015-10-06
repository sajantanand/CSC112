#	Programmer:	Sajant Anand			Course: CSC112 Anand
#	Assignment: Lab9					Date:	4/7/15
CC = g++
CFLAGS = -Wall -pedantic -g
driver: driver.o pixel.o
	$(CC) -o driver driver.o pixel.o
driver.o: driver.cpp pixel.h
	$(CC) $(CFLAGS) -c driver.cpp
pixel.o: pixel.cpp colors.h
	$(CC) $(CFLAGS) -c pixel.cpp

clean:
	\rm -f *.o driver