/** 
 *  @file    pixellist2.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/14/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 10, contains half of the functions delcared in words.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the class functions and operator overloads that were
 *  declared in pixellist.h. These functions are used to do various
 *  manipulations of the PixelList class. The methods included are those that
 *  are operator overloads.
 *
 */

#include <iostream>
#include <cassert>
#include "pixel.h"
#include "pixellist.h"

using namespace std;

/**
  *   @brief  overloads assignment operator so that pixels can be compared in *   one line
  *  
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return const PixelList - returns left hand side
  */
const PixelList PixelList::operator=(const PixelList& rhs)
{
    if(this != &rhs)
    {
        if(list_)
        {
            delete [] list_;
        }

        size_ = rhs.size_;

        if(rhs.size_ > 0)
        {
            list_ = new (nothrow) Pixel[rhs.size_];     //new list
            assert(list_);

            for(int i = 0; i < size_; i++)
                list_[i] = rhs.list_[i];
        }
        else
        {
            list_ = 0;
        }
    }

    return *this;
}

/**
  *   @brief  overloads plus operator so that two pixel lists can be combined into one list. This works for two pixel lists or a pixel list and a pixel. If a pixel is provided in the fuctions, the pixel is implicitly converted into a pixel list and then this operator is called
  * 
  *   @param  lhs is an constant reference pixel (user-defined type) 
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return PixelList - returns combined left and right hand side
  */
PixelList operator+(const PixelList& lhs, const PixelList& rhs)
{
    PixelList temp;     ///<temporary pixellist object
    if(lhs.size_ >= rhs.size_)
    {
        temp = lhs;

        for(int i = 0; i < rhs.size_; i++)
        {
            temp.list_[i] = lhs.list_[i] + rhs.list_[i];
        }

        return temp;
    }
    else
    {
        temp = rhs;
        
        for(int i = 0; i < lhs.size_; i++)
        {
            temp.list_[i] = rhs.list_[i] + lhs.list_[i];
        }

        return temp;
    }
}

/**
  *   @brief  overloads equality operator that determines if two pixel lists are the same
  * 
  *   @param  lhs is an constant reference pixel (user-defined type) 
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return bool - whether lists are the same
  */
bool operator==(const PixelList& lhs, const PixelList& rhs)
{
    bool equal = true;      ///<whether lists are equal

    if(lhs.size_ >= rhs.size_)
    {
        for(int i = 0; i < rhs.size_ && equal; i++)
        {
            //lhs.list_[i] += rhs.list_[i];
            equal = (lhs.list_[i] == rhs.list_[i]);
        }
    }
    else
    {
        for(int i = 0; i < lhs.size_ && equal; i++)
        {
            //rhs.list_[i] += lhs.list_[i];
            equal = (lhs.list_[i] == rhs.list_[i]);
        }
    }

    return equal;
}

/**
  *   @brief  overloads inequality operator that determines if two pixel lists are not the same. While I could've called the equality overloaded operator from this function, I chose to not do so.
  * 
  *   @param  lhs is an constant reference pixel (user-defined type) 
  *   @param  rhs is an constant reference pixel (user-defined type)
  *   @return bool - whether lists are the not the same
  */
bool operator!=(const PixelList& lhs, const PixelList& rhs)
{
    bool inequalityFound = false;   ///<Whether lists are unequal

    if(lhs.size_ >= rhs.size_)
    {
        for(int i = 0; i < rhs.size_ && !inequalityFound; i++)
        {
            //lhs.list_[i] += rhs.list_[i];
            inequalityFound = (lhs.list_[i] != rhs.list_[i]);
        }
    }
    else
    {
        for(int i = 0; i < lhs.size_ && !inequalityFound; i++)
        {
            //rhs.list_[i] += lhs.list_[i];
            inequalityFound = (lhs.list_[i] != rhs.list_[i]);
        }
    }

    return inequalityFound;
}

ostream& operator<<(ostream& out, const PixelList& rhs)
{
    /*out << '[' << RED << (int) rhs.red_ << NORM << ", " << GREEN << (int) rhs.green_ << NORM << ", " << BLUE << (int) rhs.blue_ << NORM << ']';
    return out;*/
    out << '{';

    for(int i = 0; i < rhs.size_; i++)
    {
        if(i != 0)
            out << ',';

        out << rhs.list_[i];
    }

    out << '}';

    return out;
}