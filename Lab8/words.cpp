/** 
 *  @file    words.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    4/1/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 8, contains the functions delcared in words.h
 *
 *  @section DESCRIPTION
 *  
 *  This file contains the functions that do the primary work needed for
 *	the program; applications include reading text files and counting the 
 *	occurance of words
 *
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include <cstdlib>
#include <algorithm>

#define OUT_OF_MEMORY 1
#define BAD_INPUT_FILE 2
#define BAD_OUTPUT_FILE 3
#define BAD_STOP_WORD_FILE 4

using namespace std;

#include "words.h"

/**
  *   @brief  Reads in each word of file sequentially so that it can
  *		be parsed correctly
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to use
 *    @param  wordList is an reference pointer to a WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  szie is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void readFile(char fileName[], WordFreq *&wordList, int& size)
{
	fstream inFile(fileName, ios::in);		///< Initializes fstream

	if (inFile.fail())
	{
		cout << fileName << " is not a valid input file; please execute this "
			 << "program again with a different file name." << endl;
		exit(BAD_INPUT_FILE);
	}

	int n = 1;					///< Length of word being read
	char ch;					///< Holds each character as it is being processed

	char *str = new (nothrow) char[1];	///< Dynamic C-String

	str[0] = '\0';

	ch = inFile.get();

	while(!inFile.eof())
	{

		if(ch == ' ' || ch == '\n' || ch == ',' || ch == '.' || ch == '!'
			|| ch == '?' || ch == ';' || ch == '"' || ch == '(' || ch == ')'
			|| ch == ':' || ch == '\'')
		{
			if(isWord(str))
			{
				addWordToList(str, wordList, size);
			}
			str[0] = '\0';
			n = 1;
		}
		else
		{
			char *newSTR = new (nothrow) char[n + 1];	///< Dynamic C-String
						///< of increased size

			for(int i = 0; i < n; i++)
			{
				newSTR[i] = str[i];
			}

			newSTR[n - 1] = tolower(ch);
			newSTR[n] = '\0';

			if((int*)str) 
			{
				delete [] str;
			}

			str = newSTR;
			n++;
		}
		ch = inFile.get();
	}

	inFile.close();
	cout << fileName << " has " << size << " unique words" << endl;

	int k = 0;				///< Counter variable used for styling
	while (k < 47)
	{
		cout << "-";
		k++;
	}
	cout << endl;
}

/**
  *   @brief  Determines if word candidate is a word
  *  
  *	  @param  wordPos is a reference (by default) C-String that holds
  *		the word to be processed
  *   @return bool - whether wordPos is a word or not
  */
bool isWord(char wordPos[])
{
	int n = strlen(wordPos);	///< Length of C-String

	bool word = true;			///< Whether wordPos is a string

	if(n == 0)
		word = false;

	for(int i = 0; i < n && word; i++)
	{
		if(!isalpha(wordPos[i]))
		{
			word = false;
		}
	}

	return word;
}

/**
  *   @brief  Either adds each word to the array passed into the 
  *		function or increments the number of occurances depending on if
  *		the word is already in the array
  *  
  *	  @param  wordPos is a reference (by default) C-String that holds
  *		the word to be processed
  *   @param  list is an reference (by default) WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  num is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void addWordToList(char wordPos[], WordFreq *&list, int& num)
{
	int loc = contains(list, num, wordPos);	///< Position in array
	if(loc != -1)
	{
		list[loc].count++;
	}
	else
	{
		WordFreq *newList = new (nothrow) WordFreq[num + 1];

		if (!newList)
		{
			cout << "Out of memory. . ." << endl;
			exit(OUT_OF_MEMORY);
		}

		for(int i = 0; i < num; i++)
		{
			*(newList + i) = *(list + i);
		}

		if (list)
		{
			delete [] list;
		}

		memcpy((*(newList + num)).word, wordPos, strlen(wordPos)+1);

		newList[num].count++;
		num++;

		list = newList;
	}
}

/**
  *   @brief  Searches an array for a particular word and returns the
  *		location of word if present in array
  *  
  *   @param  wordList is an reference (by default) WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  size is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *	  @param  str is a reference (by default) C-String that holds
  *		the word to be searched for
  *   @return int - location of target word in array; if target is not
  *		in array, returns -1
  */
int contains(WordFreq wordList[], int size, char str[])
{
	bool found = false;		///< Bool used for exiting loop early
	int location = -1;		///< Location of char in array
	int i = 0;				///< Local loop counter

	while(i < size && !found)
	{
		if (memcmp(wordList[i].word, str, strlen(str) + 1) == 0)
		{
			location = i;
			found = true;
		}
		i++;
	}

	return location;
}

/**
  *   @brief  Writes each word of the sorted array to a file so that it can
  *		be used to generate a word cloud
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to write to
  *   @param  wordList is an reference (by default) WordFreq array
  *		(user-defined type) that holds all the unique words and the
  *		number of times they have appeared
  *	  @param  size is an interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void writeFile(char fileName[], WordFreq wordList[], int size)
{
	int k = 0;					///< Counter variable used for styling
	while (k < 47)
	{
		cout << "-";
		k++;
	}

	cout << endl << "Creating " << fileName << " . . .   " << flush;

	fstream outFile;			///< Initializes fstream

	outFile.open(fileName, ios::out);
	if(outFile.fail())
	{
		cout << fileName << " is not a valid output file; please execute this "
			 << "program again with a different file name." << endl;
		exit(BAD_OUTPUT_FILE);
	}

	for(int i = 0; i < size; i++)
		outFile << wordList[i];

	outFile.close();

	cout << "done!" << endl;
}

/**  
  *   @brief  displays output to the user  
  *
  *	  @param  size is a interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to write to
  *   @return void  
  */ 
void display(int size, char fileName[])
{
	cout << fileName << " has " << size << " unique words" << endl;
}

/**
  *   @brief  reads the stop word text file and checks list to see if a
  *		match occurs; if it does, call a function to remove this match
  *		from list
  *  
  *   @param  wordList is an reference pointer to a WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  size is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to write to
  *   @return void
  */
void readStopWords(WordFreq *&wordList, int &size, char fileName[])
{
	fstream inFile(fileName, ios::in);		///< Initializes fstream

	if (inFile.fail())
	{
		cout << fileName << " is not a valid stop word file; please execute this "
			 << "program again with a different file name." << endl;
		exit (BAD_STOP_WORD_FILE);
	}

	int n = 1;				///< Length of word being read
	char ch;				///< Holds each character as it is being processed

	char *str = new (nothrow) char[1];	///<Dynamic C-String

	str[0] = '\0';

	ch = inFile.get();
	while(!inFile.eof())
	{

		if(ch == ' ' || ch == '\n')
		{
			if(isWord(str))
			{
				removeRedundancies(str, wordList, size);
			}
			str[0] = '\0';

			n = 1;
		}
		else
		{
			char *newSTR = new (nothrow) char[n + 1];
					///< Dynamic C-String of increased size

			for(int i = 0; i < n; i++)
			{
				newSTR[i] = str[i];
			}

			newSTR[n - 1] = tolower(ch);
			newSTR[n] = '\0';

			if((int*)str) 
			{
				delete [] str;
			}

			str = newSTR;
			n++;
		}
		ch = inFile.get();
	}
	inFile.close();

	cout << endl << "without stop words (read from " << fileName << ")" << endl;
}

/**
  *   @brief  removes the wordFreq object if a match is found between of the
  *		stop word and an entry in the list.
  *  
  *   @param  wordPos is an reference (by default) character array (C-String)
  *		that holds the stop word that the list is being scanned for
  *   @param  list is an reference pointer to a WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  num is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void removeRedundancies(char wordPos[], WordFreq *&list, int& num)
{
	bool removed = false;			///< Boolean used to exit for loop
	for(int i = 0; i < num && !removed; i++)
	{
		if(memcmp(wordPos, list[i].word, strlen(wordPos)+1) == 0)
		{
			WordFreq *newList = new (nothrow) WordFreq[num-1];
									///< New, smaller dynamic array
			if (!newList)
			{
				cout << "Out of memory. . ." << endl;
				exit(OUT_OF_MEMORY);
			}

			int k = 0;				///< Counter for smaller list

			for(int j = 0; j < num; j++)
			{
				if( j != i)
				{
					memcpy(newList[k].word, list[j].word, strlen(list[j].word)+1);
					newList[k].count = list[j].count;
					k++;
				}
			}

			delete [] list;			///< Deletes older, larger list
			list = newList;

			removed = true;
			num--;
		}
	}
}

/**  
  *   @brief  clears an Xterm window  
  *
  *	  @param void
  *   @return void  
  */  
void clearScreen()
{
   cout << char(27) << "[;H" << char(27) << "[2J" << '\n';
}

/**
  *   @brief  overloads output operator so that WordFreq can be outputed in *   one line
  *  
  *   @param  file is an reference fstream that holds the output stream needed *     to write to a file
  *   @param  word1 is an constant reference WordFreq (user-defined type)
  *   @return fstream - so that operator can be chained
  */
fstream& operator<<(fstream& file, const WordFreq& word1)
{
	file << word1.word << " " << word1.count << endl;
	return file;
}

/**
  *   @brief  overloads equality operator so that WordFreq can be compared in *   one line
  *  
  *   @param  word1 is an constant reference WordFreq (user-defined type)
  *   @param  word2 is an constant reference WordFreq (user-defined type)
  *   @return bool - if two WordFreqs are the same
  */
bool operator==(const WordFreq& word1, const WordFreq& word2)
{
	return (memcmp(word1.word, word2.word, strlen(word1.word)+1) == 0);
}

/**
  *   @brief  less-than operator so that WordFreq can be ordered               *       alphabetically in one line
  *  
  *   @param  word1 is an constant reference WordFreq (user-defined type)
  *   @param  word2 is an constant reference WordFreq (user-defined type)
  *   @return bool - if word1 is before word 2
  */
bool operator>(const WordFreq& word1, const WordFreq& word2)
{
	int memory = max(strlen(word1.word), strlen(word2.word));
		///< Holds bites used by larger string
	if(memcmp(word1.word, word2.word, memory) < 0)
		return false;
	else 
		return true;
}