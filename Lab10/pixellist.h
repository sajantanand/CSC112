/** 
 *  @file    pixellist.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/14/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 10, contains function header and struct necessary for
 *		for pixellist1.cpp and pixellist2.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class and function declarations needed for the
 *	program execution
 *
 */

#ifndef PIXELLIST_H
#define PIXELLIST_H

#include <iostream>
using namespace std;

class PixelList
{
	public:
		PixelList();								//Null constructor
		PixelList(const Pixel& starter);			//One pixel constructor
		PixelList(const PixelList& listToCopy);		//Copy constructor

		~PixelList();								//Destructor

		int size() const;							//Getter for size
		void append(const Pixel& element);			//Adds pixel to list

		const PixelList operator=(const PixelList& rhs);
				//Overloaded assignment - assigns right list to calling list
		friend PixelList operator+(const PixelList& lhs, const PixelList& rhs);
				//Overloaded addition - combines two lists into a single one
		friend bool operator==(const PixelList& lhs, const PixelList& rhs);
				//Overloaded equality - returns true if lists are equala
		friend bool operator!=(const PixelList& lhs, const PixelList& rhs);
				//Overloaded inequality - returns true if lists are unequal
		friend ostream& operator<<(ostream& out, const PixelList& rhs);
				//Overloaded output - displays lists

	private:
		Pixel *list_;			//Pointer to list of pixels
		int size_;				//Number of pixels in list
};

#endif