/** 
 *  @file    lab7.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    3/27/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 7, reads in text file and creates frequency file
 *		after common stop words are removed
 *
 *  @section DESCRIPTION
 *  
 *  This program counts the number of distinct words used in a text
 *	file and the number of times that each word appears. Then another file
 *	is read (stop words) and any matches are removed. This data is then
 *	written to a text file to be used to generate a word cloud
 *
 */

#include <iostream>
#include <cstdlib>

#include "words.h"

#define IMPROPER_FILE_NAME 5

using namespace std;


/** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @param void
  *   @return int - used as a status indicator
  */ 
int main(int argc, char *argv[])
{
	clearScreen();

	if(argc < 4)
	{
		cout << "usage: " << argv[0] << " inputTextFile stopWordsFile outputTextFile" << endl;
		exit(IMPROPER_FILE_NAME);
	}

	WordFreq *list = NULL;				///< WordFreq array to hold unique words
	int num = 0;						///<Logical size of WordFreq array

	readFile(argv[1], list, num);

	sortWordList(list, num);

	readStopWords(list, num, argv[2]);

	display(num, argv[1]);

	writeFile(argv[3], list, num);
	
	return 0;
}