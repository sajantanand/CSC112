/** 
 *  @file    pixelnode.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/24/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 11, contains function header and struct necessary for
 *		for pixelnode.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class and function declarations needed for the
 *	program execution
 *
 */

#ifndef PIXELNODE_H
#define PIXELNODE_H

#include <iostream>
using namespace std;

class PixelNode
{
	public:
		PixelNode(Pixel starter = Pixel(255,255,255), PixelNode *n = 0)
			{	value_ = starter; next_ = n;	}
			//Constructor with default values - functions also as null constructor
		PixelNode(const PixelNode& starterNode);
			//Constructor from Pixel Node
		~PixelNode();	//Destructor

		const Pixel& value() const;
			//Accessor for value_
		PixelNode* next() const;
			//Reader/accessor for next_
		PixelNode*& next();
			//Writer/accessor for next_

		const PixelNode& operator=(const PixelNode& RHS);
			//Overloaded equality operator
		friend ostream& operator<<(ostream& out, const PixelNode& rhs);
			//Overloaded output operator - friend

		bool deleteNode(PixelNode *ptr);
			//Function called in destructor
	private:
		Pixel value_;		///<stores pixel
		PixelNode *next_;	///<stores address of next PixelNode
};

#endif