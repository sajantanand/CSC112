/** 
 *  @file    pixel.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/7/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 9, contains the functions delcared in words.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class functions and operator overloads that were
 *	declared in words.h. These functions are used to do various manipulations
 *	of the pixel class. 
 *
 */

#include <iostream>
#include "pixel.h"
#include "colors.h"

using namespace std;

/**
  *   @brief  Constructor used for the pixel class; the constructor has
  *	  default values proved so that the constructor is versitile and can be
  *	  used in many situaiton.
  *  
  *   @param  red is an integer variable storing red values for pixel
  *   @param  green is an integer variable storing green values for pixel
  *   @param  blue is an integer variable storing blue values for pixel
  *   @return No return type - Constructor
  */
Pixel::Pixel(int red, int green, int blue)
{
	red_ = clip(red);
	green_ = clip(green);
	blue_ = clip(blue);
}

/**
  *   @brief  accessory for red data member
  *  
  *   @param  none
  *   @return unsigned char -  value for red property
  */
unsigned char Pixel::red() const
{
	return red_;
}

/**
  *   @brief  accessory for green data member
  *  
  *   @param  none
  *   @return unsigned char -  value for green property
  */
unsigned char Pixel::green() const
{
	return green_;
}

/**
  *   @brief  accessory for blue data member
  *  
  *   @param  none
  *   @return unsighed char - value for blue property
  */
unsigned char Pixel::blue() const
{
	return blue_;
}

/**
  *   @brief  setter for red data member
  *  
  *   @param  color is an integer variable storing values for pixel
  *   @return bool value - if number was clipped
  */
bool Pixel::setRed(int color)
{
	if(color >= 0 && color <= 255)
	{
		red_ = color;
		return true;
	}
	else
	{
		red_ = clip(color);
		return false;
	}
}

/**
  *   @brief  setter for blue data member
  *  
  *   @param  color is an integer variable storing values for pixel
  *   @return bool value - if number was clipped
  */
bool Pixel::setGreen(int color)
{
	if(color >= 0 && color <= 255)
	{
		green_ = color;
		return true;
	}
	else
	{
		green_ = clip(color);
		return false;
	}
}

/**
  *   @brief  setter for blue data member
  *  
  *   @param  color is an integer variable storing values for pixel
  *   @return bool - if number was clipped
  */
bool Pixel::setBlue(int color)
{
	if(color >= 0 && color <= 255)
	{
		blue_ = color;
		return true;
	}
	else
	{
		blue_ = clip(color);
		return false;
	}
}

/**
  *   @brief  accessory/calculator for grayscale data member
  *  
  *   @param  none
  *   @return unsigned char - value for grayscale property
  */
unsigned char Pixel::grayscale() const
{
	return (.2989 * red_ + .5870 * green_+ .1140 * blue_);
}

/**
  *   @brief  limits a value once it exceeds a threshold (below 0 or above 255)
  *  
  *   @param  value is an integer variable storing values for pixel
  *   @return unsigned char - clipped number
  */
unsigned char Pixel::clip(int value)
{
	if(value > 255)
		value = 255;
	else if (value < 0)
		value = 0;

	return value;
}

/**
  *   @brief  overloads output operator so that pixel can be outputed in
  *   one line (with COLOR!!!!!!)
  *  
  *   @param  out is an reference ostream that holds the output stream needed *     to write to the terminal
  *   @param  rhs is an constant reference WordFreq (user-defined type)
  *   @return ostream - so that operator can be chained
  */
ostream& operator<<(ostream& out, const Pixel& rhs)
{
	out << '[' << RED << (int) rhs.red_ << NORM << ", " << GREEN << (int) rhs.green_ << NORM << ", " << BLUE << (int) rhs.blue_ << NORM << ']';
	return out;
}

/**
  *   @brief  overloads equality operator so that pixels can be compared in *   one line
  *  
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return bool - if two WordFreqs are the same
  */
bool Pixel::operator==(const Pixel& rhs)
{
	return((red_== rhs.red_) && (green_ == rhs.green_) && (blue_ == rhs.blue_));
}

/**
  *   @brief  overloads equality operator so that pixels can be compared in *   one line (determines if unequal)
  *  
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return bool - if two WordFreqs are the unequal
  */
bool Pixel::operator!=(const Pixel& rhs)
{
	return((red_ != rhs.red_) || (green_ != rhs.green_) || (blue_ != rhs.blue_));
}

/**
  *   @brief  overloads plus operator so that pixels can be added together to
  *   yield one pixel
  *  
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return pixel - a pixel that combines the values of the two arguements
  */
Pixel Pixel::operator+(const Pixel& rhs)
{
	Pixel temp(clip(red_ + rhs.red_), clip(green_ + rhs.green_), clip(blue_ + rhs.blue_));

	return temp;
}