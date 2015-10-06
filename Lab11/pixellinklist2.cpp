/** 
 *  @file    pixellinklist2.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/28/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 12, contains the second set of the functions delcared in pixellinklist.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class functions and operator overloads that were
 *  declared in pixellinklist.h. These functions are used to do various
 *  manipulations of the PixelLinkList class.
 *
 */

#include <iostream>
#include <cassert>
#include "pixel.h"
#include "pixellist.h"
#include "pixelnode.h"
#include "pixellinklist.h"

using namespace std;

/**
  *   @brief  overloads addition operator; concatenates two link lists together into a single one
  * 
  *   @param  LHS is an constant reference PixelLinkList (user-defined type
  *   @param  RHS is an constant reference PixelLinkList (user-defined type)
  *   @return PixelLnkList
  */
PixelLinkList operator+(const PixelLinkList& LHS, const PixelLinkList& RHS)
{
	PixelLinkList temp1(LHS);		//Copy of LHS using copy constructor
	PixelLinkList temp2(RHS);		//Copy of RhS using copy constructor

	if(temp1.head_ == 0) return temp2;

	PixelNode *ptr = temp1.head_;	//pointer used for iterating through loop

	while(ptr->next())
	{
		ptr = ptr->next();
	}

	ptr->next() = temp2.head_;

	temp2.head_ = 0;

	return temp1;
}

/**
  *   @brief  removes all occurances of a pixel from the linked list
  * 
  *   @param  pix is an constant reference Pixel (user-defined type
  *   @return void - not really useful
  */
void PixelLinkList::remove(const Pixel& pix)
{
	if(head_ == 0)
		return;		//used to exit the function early

	PixelNode *current = head_;		//pointer used for interating through loop
	PixelNode *previous = head_;	//pointer used for interating through loop

	while(head_ && head_->value() == pix)
	{
		head_ = head_->next();
		current->next() = 0;
		delete current;
		current = head_;
	}

	while(current)
	{
		if(current->value() == pix)
		{
			previous->next() = current->next();
			current->next() = 0;
			delete current;
			current = previous->next();
		}
		else
		{
			previous = current;
			current = current->next();
		}
	}
}