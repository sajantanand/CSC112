/** 
 *  @file    words.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/1/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 8, contains function header and struct necessary for
 *		for words.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the struct and function declarations needed for the
 *	program execution
 *
 */

#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <fstream>

#define MAX_STRING_SIZE 20

using namespace std;


/** 
  *   @brief  data structure used to create Word array; holds both the 
  *	  word and the number of times it has appeared in file 
  */ 
struct WordFreq
{
	WordFreq()
	{
		word[0] = '\0';
		count = 0;			
	}

	char word[MAX_STRING_SIZE];	///< Unique word
	int count;					///< Number of times characters occurs in file
};

void readFile(char fileName[], WordFreq *&wordList, int& size);
void clearScreen();
bool isWord(char wordPos[]);
void addWordToList(char wordPos[], WordFreq *&list, int& num);
int contains(WordFreq wordList[], int size, char str[]);
void writeFile(char fileName[], WordFreq wordList[], int size);
void display(int size, char fileName[]);
void readStopWords(WordFreq *&wordList, int &size, char fileName[]);
void removeRedundancies(char wordPos[], WordFreq *&list, int& num);


// Operator Overloads

fstream& operator<<(fstream& file, const WordFreq& word1);
bool operator==(const WordFreq& word1, const WordFreq& word2);
bool operator>(const WordFreq& word1, const WordFreq& word2);

#endif