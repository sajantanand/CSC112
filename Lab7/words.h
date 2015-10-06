/** 
 *  @file    words.h
 *  @author  Sajant Anand (anans14) Section A
 *  @date    3/27/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 7, contains function header and struct necessary for
 *		for words.cpp and lab7.cpp
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the struct and function declarations needed for the
 *	program execution
 *
 */

#ifndef WORDS_H
#define WORDS_H

#define MAX_STRING_SIZE 20

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
void sortWordList(WordFreq wordList[], int size);
void writeFile(char fileName[], WordFreq wordList[], int size);
void display(int size, char fileName[]);
void readStopWords(WordFreq *&wordList, int &size, char fileName[]);
void removeRedundancies(char wordPos[], WordFreq *&list, int& num);

#endif