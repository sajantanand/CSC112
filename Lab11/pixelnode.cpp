/** 
 *  @file    pixellist2.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/14/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 11, contains all the functions delcared in pixelnode.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class functions and operator overloads that were
 *  declared in pixelnode.h. These functions are used to do various
 *  manipulations of the PixelNOde class.
 *
 */

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "pixel.h"
#include "pixelnode.h"

using namespace std;

/**
  *   @brief  constructor that builds a node from another node - copy constructor
  *  
  *   @param  starterNode is an constant reference PixelNode (user-defined type)
  *   @return N/A constructor
  */
PixelNode::PixelNode(const PixelNode& starterNode)
{
	value_ = starterNode.value_;
	PixelNode *src = starterNode.next_;
	PixelNode *dst = this;	

	while(src)
	{
		dst->next_ = new (nothrow) PixelNode(src->value_);
		assert(dst->next_);
		dst = dst->next_;
		src = src->next_;
	}

	dst->next_ = 0;
}

/**
  *   @brief  destructor for PixelNode class
  *  
  *   @param  none
  *   @return N/A destructor
  */
PixelNode::~PixelNode()
{
	if(this->next_)
	{
		deleteNode(this->next_);
	}
}

/**
  *   @brief  overloads output operator; all subsequent nodes that follow the arguement node are also printed
  * 
  *   @param  out is an reference ostream 
  *   @param  rhs is an constant reference PixelNode (user-defined type)
  *   @return out - ostream
  */
ostream& operator<<(ostream& out, const PixelNode& rhs)
{
	const PixelNode *cursor = &rhs;
		//pointer used in while loop to index through list
	while(cursor)
	{
		cout << "{" << cursor->value_ << " (" << cursor->next_ << ")}";

		if(cursor->next_ != 0)
			cout << "-> ";

		cursor = cursor->next_;
	}

	return out;
}

/**
  *   @brief  access for value data member and does not allows for this member to be changed
  * 
  *   @param  null
  *   @return constant reference Pixel
  */
const Pixel& PixelNode::value() const
{
	return value_;
}

/**
  *   @brief  access for next_ data member and does not allows for this member to be changed
  * 
  *   @param  null
  *   @return pointer to Pixel Node
  */
PixelNode* PixelNode::next() const
{
	return next_;
}

/**
  *   @brief  access for next_ data member and allows for this member to be changed
  * 
  *   @param  null
  *   @return reference pointer to Pixel Node
  */
PixelNode*& PixelNode::next()
{
	return next_;
}

/**
  *   @brief  deletes all pixel nodes following arguement node
  * 
  *   @param  prt is an pointer to a PixelNode (user-defined type)
  *   @return bool - whether anything was deleted
  */
bool PixelNode::deleteNode(PixelNode *ptr)
{
	if(ptr == 0) return false;
	
	PixelNode *previous = ptr;
		//pointer used to delete following nodes
	PixelNode *cursor = ptr;
		//pointer used to delete following nodes

	while(cursor)
	{
		cursor = cursor->next_;
		previous->next_ = 0;
		delete previous;
		previous = cursor;
	}

	return true;

}

/**
  *   @brief  overloads equality operator; makes a deep copy
  * 
  *   @param  rhs is an constant reference PixelNode (user-defined type)
  *   @return constant reference PixelNode
  */
const PixelNode& PixelNode::operator=(const PixelNode& RHS)
{
	if(this != &RHS)
	{
		value_ = RHS.value_;
		cout << 1 << endl;
		if(this->next_)
			deleteNode(this->next_);
		cout << 2 << endl;

		if(RHS.next_)
		{
			PixelNode *temp = new (nothrow) PixelNode(*(RHS.next_));
				//temporary PixelNode to hold copy of RHS
			cout << *temp << endl;
			assert(temp);
			next_ = temp;
			temp = 0;
		}
	}
	return *this;
}