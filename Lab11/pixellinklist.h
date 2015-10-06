/** 
 *  @file    pixellinklist.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/24/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 11, contains function header and struct necessary for
 *		for pixellinklist1.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class and function declarations needed for the
 *	program execution
 *
 */

#ifndef PIXELLINKLIST_H
#define PIXELLINKLIST_H

#include <iostream>
using namespace std;

class PixelLinkList
{
	public:
		PixelLinkList();
			//null constructor
		PixelLinkList(const Pixel& starter);
			//constructor from Pixel
		PixelLinkList(const PixelList& list);
			//constructor from PixelLIst
		PixelLinkList(const PixelLinkList& list);
			//copy constructor
		~PixelLinkList();
			//destructor
		void append(const Pixel& pix);
			//adds node to end of link list
		int size() const;
			//returns size of link list
		const PixelLinkList& operator=(const PixelLinkList& RHS);
			//overloaded equality operator
		void remove(const Pixel& pix);
			//removes all occurances of a pixel from the list
		friend ostream& operator<<(ostream& out, const PixelLinkList& RHS);
			//overloaded output operator - friend
		friend PixelLinkList operator+(const PixelLinkList& LHS, const PixelLinkList& RHS);
	private:
		PixelNode *head_;
			//Pixel Node to the first element in link list
};

#endif