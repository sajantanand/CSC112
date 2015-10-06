#	Programmer:	Sajant Anand			Course: CSC112 Anand
#	Assignment: Lab10					Date:	4/7/15
CC = g++
CFLAGS = -Wall -pedantic -g
driver: driver.o pixel.o pixellist1.o pixellist2.o
	$(CC) -o driver driver.o pixel.o pixellist1.o pixellist2.o
driver.o: driver.cpp pixel.h pixellist.h
	$(CC) $(CFLAGS) -c driver.cpp
pixel.o: pixel.cpp colors.h
	$(CC) $(CFLAGS) -c pixel.cpp
pixellist1.o:  pixellist1.cpp pixel.h
	$(CC) $(CFLAGS) -c pixellist1.cpp
pixellist2.o:  pixellist2.cpp pixel.h
	$(CC) $(CFLAGS) -c pixellist2.cpp

clean:
	\rm -f *.o driver