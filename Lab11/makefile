#	Programmer:	Sajant Anand			Course: CSC112 Anand
#	Assignment: Lab11					Date:	4/23/15
CC = g++
CFLAGS = -Wall -pedantic -g
driver12: driver12.o pixel.o pixellist1.o pixellist2.o pixelnode.o pixellinklist1.o pixellinklist2.o
	$(CC) -o driver12 driver12.o pixel.o pixellist1.o pixellist2.o pixelnode.o pixellinklist1.o pixellinklist2.o
driver12.o: driver12.cpp pixel.h pixellist.h pixelnode.h pixellinklist.h
	$(CC) $(CFLAGS) -c driver12.cpp
pixel.o: pixel.cpp colors.h
	$(CC) $(CFLAGS) -c pixel.cpp
pixellist1.o:  pixellist1.cpp pixel.h
	$(CC) $(CFLAGS) -c pixellist1.cpp
pixellist2.o:  pixellist2.cpp pixel.h
	$(CC) $(CFLAGS) -c pixellist2.cpp
pixelnode.o:	pixelnode.cpp pixelnode.h
	$(CC) $(CFLAGS) -c pixelnode.cpp
pixellinklist1.o:  pixellinklist1.cpp pixellinklist.h
	$(CC) $(CFLAGS) -c pixellinklist1.cpp
pixellinklist2.o:  pixellinklist2.cpp pixellinklist.h
	$(CC) $(CFLAGS) -c pixellinklist2.cpp

clean:
	\rm -f *.o driver12