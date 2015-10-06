/** 
 *  @file    pixel.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/1/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 10, contains function header and struct necessary for
 *		for pixel.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class and function declarations needed for the
 *	program execution
 *
 */

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
using namespace std;

/** 
  *   @brief  data structure used to create Pixel; holds both the 
  *	  color values and the functions that manipulate these values
  */
class Pixel
{
	public:
		Pixel(int red = 255, int green = 255, int blue = 255);
					//Constructor with default values

		unsigned char red() const;		//getter for red property
		unsigned char green() const;		//getter for red property
		unsigned char blue() const;		//getter for red property

		unsigned char grayscale() const;		//getter for greyscale

		bool setRed(int color);		//setter for red property
		bool setGreen(int color);	//setter for red property
		bool setBlue(int color);	//setter for red property

		Pixel operator+(const Pixel& rhs);	//plus operator
		bool operator!=(const Pixel& rhs);	//inequality operator
		bool operator==(const Pixel& rhs);	//equality operator

		friend ostream& operator<<(ostream& out, const Pixel& rhs);
								//output operator

	private:
		unsigned char red_;		//red data property
		unsigned char green_;	//green data property
		unsigned char blue_;	//blue data proptery

		unsigned char clip(int value);		//clipping method for limiting values
};




#endif