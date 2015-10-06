/** 
 *  @file    stemming.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/1/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 8, contains function header and struct necessary for
 *		for stemming.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the struct and function declarations needed for the
 *	stemming functionally
 *
 */

#ifndef STEMMING_H
#define STEMMING_H

using namespace std;

#include "words.h"

void stemList(char fileName[], WordFreq *&wordList, int& size);
void collapseList(WordFreq*& list, int& num);

#endif