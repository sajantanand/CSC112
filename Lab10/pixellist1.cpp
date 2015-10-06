/** 
 *  @file    pixellist1.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/14/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 10, contains half of the functions delcared in words.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class functions and operator overloads that were
 *	declared in pixellist.h. These functions are used to do various
 *	manipulations of the PixelList class. The methods included are those that
 *	aren't operator overloads.
 *
 */

#include <iostream>
#include <cassert>
#include "pixel.h"
#include "pixellist.h"

using namespace std;

/**
  *   @brief  Null Constructor used for the pixel class
  *  
  *   @return No return type - Constructor
  */
PixelList::PixelList()
{
  size_ = 0;
  list_ = 0;
}

/**
  *   @brief  One pixel constructor used for the pixel class; the constructor
  *		intializes the list with one pixel and therefore it has a size of one.
  *  
  *   @param  starter is a reference pixel object
  *   @return No return type - Constructor
  */
PixelList::PixelList(const Pixel& starter)
{
    list_ = new (nothrow) Pixel[1];		//new list for pixel list
    assert(list_);
    size_ = 1;
    list_[0] = starter;
}

/**
  *   @brief  Copy constructor used for the pixel class; the constructor
  *		intializes the list as an exact copy as the arguement.
  *  
  *   @param  starter is a const reference pixellist object
  *   @return No return type - Constructor
  */
PixelList::PixelList(const PixelList& listToCopy)
{
    if(listToCopy.size_ > 0)
    {
        list_ = new (nothrow) Pixel[listToCopy.size_];		//new list for pixel list
        assert(list_);
        size_ = listToCopy.size_;
        for(int i = 0; i < size_; i++)
        {
            list_[i] = listToCopy.list_[i];
    	}
    }
    else
    {
        list_ = 0;
        size_ = 0;
    }
}

/**
  *   @brief  Destructor for the PixelList()
  *  
  *   @return No return type - Destructor
  */
PixelList::~PixelList()
{
    if(list_)
        delete [] list_;

    list_ = NULL;
    size_ = 0;
}

/**
  *   @brief  Getter for the size property of the pixel list
  *  
  *   @return int - size of PixelList
  */
int PixelList::size() const
{
    return size_;
}

/**
  *   @brief  adds a pixel to the end of the pixel list
  *  
  *   @param  element is a constant reference pixel object
  *   @return int - size of PixelList
  */
void PixelList::append(const Pixel& element)
{
    Pixel *temp = new (nothrow) Pixel[size_ + 1];  //new list for pixel list
    assert(temp);

    for(int i = 0; i < size_; i++)
        temp[i] = list_[i];

    temp[size_] = element;
    size_++;

    if(list_)
    {
        delete [] list_;
    }

    list_ = temp;
}