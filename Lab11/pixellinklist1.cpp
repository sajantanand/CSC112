/** 
 *  @file    pixellinklist1.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/24/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 11, contains all the functions delcared in pixellinklist1.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class functions and operator overloads that were
 *  declared in pixellinklist.h. These functions are used to do various
 *  manipulations of the PixelNOde class.
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
  *   @brief  null constructor
  *  
  *   @param  none
  *   @return N/A constructor
  */
PixelLinkList::PixelLinkList()
{
	head_ = 0;
}

/**
  *   @brief  constructor that builds a link list from pixel
  *  
  *   @param  starter is an constant reference Pixel (user-defined type)
  *   @return N/A constructor
  */
PixelLinkList::PixelLinkList(const Pixel& starter)
{
	head_ = new (nothrow) PixelNode(starter);
		//assigns pixel to head
	assert(head_);
}

/**
  *   @brief  constructor that builds a link list from pixel list
  *  
  *   @param  list is an constant reference PixelList (user-defined type)
  *   @return N/A constructor
  */
PixelLinkList::PixelLinkList(const PixelList& list)
{
	if(list.size() == 0)
		head_ = 0;
	else
	{
		head_ = new (nothrow) PixelNode(list[0]);
			//assings initial pixel to head
		PixelNode *cursor = head_;

		for(int i = 1; i < list.size(); i++)
		{
			(*cursor).next() = new (nothrow) PixelNode(list[i]);
				//all following pixels in list are added to link list
			assert((*cursor).next());
			cursor = (*cursor).next();
		}
	}
}

/**
  *   @brief  constructor that builds a link list from another link list - copy constructor
  *  
  *   @param  list is an constant reference PixelLinkList (user-defined type)
  *   @return N/A constructor
  */
PixelLinkList::PixelLinkList(const PixelLinkList& list)
{
	if(list.head_ == 0)
		head_ = 0;
	else
	{
		head_ = new (nothrow) PixelNode(*(list.head_));
			//uses copy constructor for pixil nodes
		assert(head_);
	}
}

/**
  *   @brief  destructor for PixelLinkLIst class
  *  
  *   @param  none
  *   @return N/A destructor
  */
PixelLinkList::~PixelLinkList()
{
	if(head_)
		delete head_;
}

/**
  *   @brief  creates a pixel node form an arguement pixel and adds this node to the end of the link list
  *  
  *   @param  pix is a constant reference pixel (user-defined type)
  *   @return void
  */
void PixelLinkList::append(const Pixel& pix)
{
	if(head_ != 0)
	{
		PixelNode *cursor = head_;

		while((*cursor).next() != 0)
		{
			cursor = (*cursor).next();
		}

		(*cursor).next() = new (nothrow) PixelNode(pix);
	}
	else
	{
		head_ = new (nothrow) PixelNode(pix);
	}
}

/**
  *   @brief  returns the size of the link list by using a while loop to step through the list
  *  
  *   @param  none
  *   @return int - size of the link list
  */
int PixelLinkList::size() const
{
	int size = 0;
		//size of the array

	if(head_ == 0)
		size = 0;
	else
	{
		size = 1;
		PixelNode *cursor = head_;
			//pointer used for stepping though loop
		while((*cursor).next() != 0)
		{
			cursor = (*cursor).next();
			size++;
		}
	}
	return size;
}

/**
  *   @brief  overloads equality operator; makes a deep copy
  * 
  *   @param  rhs is an constant reference PixelLinkList (user-defined type)
  *   @return constant reference PixelLinkList
  */
const PixelLinkList& PixelLinkList::operator=(const PixelLinkList& RHS)
{
	if(this != &RHS)
	{
		if(head_) delete head_;
		PixelLinkList temp(RHS);
			//creates temporary link list using copy constructor
		head_ = temp.head_;
		temp.head_ = 0;
	}

	return *this;
}

/**
  *   @brief  overloads output operator; uses overloaded output operator of pixel node class
  * 
  *   @param  out is an reference ostream 
  *   @param  rhs is an constant reference PixelLinkList (user-defined type)
  *   @return out - ostream
  */
ostream& operator<<(ostream& out, const PixelLinkList& RHS)
{
	if(RHS.head_ == 0)
		cout << "No linked list to print out. . ." << endl;
	else
	{
		cout << *(RHS.head_);
	}
	return out;
}