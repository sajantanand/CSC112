/** 
 *  @file    stemming.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/1/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 8, contains the functions delcared in stemming.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the functions that do the stemming work needed for
 *	the program; applications include lemmaticizing words, consolidating the   *  list, and sorting the resultant.
 *
 */

#include <string.h>
#include <iostream>
#include <cstdlib>

#define OUT_OF_MEMORY 1

using namespace std;

#include "stemming.h"
#include "words.h"

/**
  *   @brief  Simplifies each word of lists sequentially so that it can
  *		be consilidated
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to use; needed for output
  *   @param  wordList is an reference pointer to a WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  size is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void stemList(char fileName[], WordFreq *&wordList, int& size)
{
	int length;			///<Length of each word
	for(int i = 0; i < size; i++)
	{
		length = strlen(wordList[i].word);

		if(length >= 6)
		{
			char last[4] = {wordList[i].word[length - 3], wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(memcmp(last, "ies", 4) == 0)
			{
				wordList[i].word[length-3] = 'y';
				wordList[i].word[length-2] = '\0';
			}

			length = strlen(wordList[i].word);
		}

		if(length >= 5)
		{
			char last[4] = {wordList[i].word[length - 3], wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(memcmp(last, "ves", 4) == 0)
				wordList[i].word[length-1] = '\0';

			length = strlen(wordList[i].word);
		}

		{ //I did this so that last would not exist for the entire function
			char last[3] = {wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(last[1] == 's' && (last[0] != 's' && last[0] != 'u'))
			{
				wordList[i].word[length-1] = '\0';
			}

			length = strlen(wordList[i].word);
		}

		if(length >= 5)
		{
			char last[4] = {wordList[i].word[length - 3], wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(memcmp(last, "ved", 4) == 0)
				wordList[i].word[length-1] = '\0';

			length = strlen(wordList[i].word);
		}

		if(length >= 5)
		{
			char last[4] = {wordList[i].word[length - 3], wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(last[1] == 'e' && last[2] == 'd')
				wordList[i].word[length-2] = '\0';

			length = strlen(wordList[i].word);
		}

		if(length >= 7)
		{
			char last[3] = {wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(memcmp(last, "ly", 3) == 0)
			{
				wordList[i].word[length-2] = '\0';
			}

			length = strlen(wordList[i].word);
		}

		if(length >= 5)
		{
			char last[4] = {wordList[i].word[length - 3], wordList[i].word[length - 2], wordList[i].word[length - 1], '\0'};
			///< C-String to hold final letters in word

			if(memcmp(last, "ing", 4) == 0)
				wordList[i].word[length-3] = '\0';
		}
	}

	collapseList(wordList, size);

	cout << "after stemming " << fileName << " has " << size << " unique words" << endl;

	int k = 0;				///< Counter variable used for styling
	while (k < 47)
	{
		cout << "-";
		k++;
	}
}

/**
  *   @brief  Consolidates and alphabetically sorts list
  *  
  *   @param  list is an reference pointer to a WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  num is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void collapseList(WordFreq*& list, int& num)
{
	for(int i = 0; i < num; i++)
	{
		for(int j = i + 1; j < num; j++)
		{
			if(list[i] == list[j] || strlen(list[j].word) == 0)
			{
				if(list[i] == list[j])
				{
					list[i].count += list[j].count;
					list[j].word[0] = '\0';
				}

				WordFreq *newList = new (nothrow) WordFreq[num-1];
										///< New, smaller dynamic array
				if (!newList)
				{
					cout << "Out of memory. . ." << endl;
					exit(OUT_OF_MEMORY);
				}

				int k = 0;				///< Counter for smaller list

				for(int z = 0; z < num; z++)
				{
					if( z != j)
					{
						memcpy(newList[k].word, list[z].word, strlen(list[z].word)+1);
						newList[k].count = list[z].count;
						k++;
					}
				}

				delete [] list;			///< Deletes older, larger list
				list = newList;

				num--;

			}
		}
	}


	WordFreq temp;		///< Dummy variable used to swap values
	int j;				///< Local loop counter

	for(int i = 1; i < num; i++)
	{
		temp.count = list[i].count;
		memcpy(temp.word, list[i].word, strlen(list[i].word) + 1);

		for( j=i; j > 0 && list[j-1] > temp; j--)
		{
			list[j].count = list[j - 1].count;
			memcpy(list[j].word, list[j - 1].word, strlen(list[j - 1].word) + 1);
		}

		list[j].count = temp.count;
		memcpy(list[j].word, temp.word, strlen(temp.word) + 1);
	}
}