/** 
 *  @file    lab6.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    3/18/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 6, reads in text file and creates frequency file
 *
 *  @section DESCRIPTION
 *  
 *  This program counts the number of distinct words used in a text
 *	file and the number of times that each word appears. This data is then
 *	written to a text file to be used to generate a word cloud
 *
 */

#include <iostream>
#include <fstream>
#include <string.h>

#define MAX_STRING_SIZE 20
#define MAX_LIST_SIZE 5000

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

void readFileName(char fileName[]);
bool readFile(char fileName[], WordFreq wordList[], int& size);
void clearScreen();
bool isWord(char wordPos[]);
void addWordToList(char wordPos[], WordFreq list[], int& num);
int contains(WordFreq wordList[], int size, char str[]);
void sortWordList(WordFreq wordList[], int size);
void writeFile(char fileName[], WordFreq wordList[], int size);
void display(int& counter);

/** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @param void
  *   @return int - used as a status indicator
  */ 
int main()
{
	clearScreen();

	int displayCount = 0;				///< How many times display() executed

	WordFreq list[MAX_LIST_SIZE] = {};	///< WordFreq array to hold unique words
	int num = 0;						///<Logical size of WordFreq array

	char nameOfFile[MAX_STRING_SIZE];	///< C-String to hold file name

	display(displayCount);

	bool success;						///< Whether input file is valid or not

	do {
		readFileName(nameOfFile);
		success = readFile(nameOfFile, list, num);
	} while (success != true);

	display(displayCount);

	sortWordList(list, num);

	writeFile(nameOfFile, list, num);
	
	return 0;
}

/**
  *   @brief  Gets input from user (name of file to be read or written to)
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to use (input or output)
  *   @return void
  */
void readFileName(char fileName[])
{
	int i = 0;		///< Local loop variable
	char ch;		///< Holds each character as it is being read
	cout << "Enter the name of the file -> ";
	
	ch = cin.get();
	while(ch != '\n' && ch != ' ' && i <( MAX_STRING_SIZE - 1))
	{
		fileName[i] = ch;
		ch = cin.get();
		i++;
	}

	fileName[i] = '\0';		///< Appends null terminator to C-String
}

/**
  *   @brief  Reads in each word of file sequentially so that it can
  *		be parsed correctly
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to use
  *   @param  wordList is an reference (by default) WordFreq array
  *		(user-defined type) that holds all the unique words and the
  *		number of times they have appeared
  *	  @param  alphaNum is a reference interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return bool - whether file was read successfully or not
  */
bool readFile(char fileName[], WordFreq wordList[], int& size)
{
	fstream inFile(fileName, ios::in);		///< Initializes fstream

	if (inFile.fail())
		return false;

	char str[MAX_STRING_SIZE];	///< Word currently being read
	int n;						///< Length of word being read
	char ch;					///< Holds each character as it is being processed

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
		}
		else
		{
			n = strlen(str);
			if(n < MAX_STRING_SIZE - 1)
			{
				str[n] = tolower(ch);
				str[n + 1] = '\0';
			}
		}
		ch = inFile.get();
	}
	inFile.close();
	cout << fileName << " has " << size << " unique words" << endl;

	return true;
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
void addWordToList(char wordPos[], WordFreq list[], int& num)
{
	int loc = contains(list, num, wordPos);	///< Position in array
	if(loc != -1)
	{
		list[loc].count++;
	}
	else if(num < MAX_LIST_SIZE)
	{
		memcpy(list[num].word, wordPos, strlen(wordPos)+1);
		list[num].count++;
		num++;
	}
	else
	{
		cout << "List out of space" << endl;
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
  *   @brief  sorts the array in descending order using inserion sort
  *  
  *   @param  wordList is an reference (by default) WordFreq array
  *		(user-defined type) that holds all the words and the number of 
  *		times they have appeared
  *	  @param  size is a interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void sortWordList(WordFreq wordList[], int size)
{
	WordFreq temp;		///< Dummy variable used to swap values
	int j;				///< Local loop counter

	for(int i = 1; i < size; i++)
	{
		temp.count = wordList[i].count;
		memcpy(temp.word, wordList[i].word, strlen(wordList[i].word) + 1);

		for(j = i; j > 0 && temp.count > wordList[j - 1].count; j--)
		{
			wordList[j].count = wordList[j - 1].count;
			memcpy(wordList[j].word, wordList[j - 1].word, strlen(wordList[j - 1].word) + 1);
		}

		wordList[j].count = temp.count;
		memcpy(wordList[j].word, temp.word, strlen(temp.word) + 1);
	}
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
  *	  @param  alphaNum is an interger variable used to hold the number
  *		of distinct words; also is size of the array
  *   @return void
  */
void writeFile(char fileName[], WordFreq wordList[], int size)
{
	fstream outFile;			///< Initializes fstream

	do
	{
		readFileName(fileName);
		outFile.open(fileName, ios::out);
	} while(outFile.fail());

	for(int i = 0; i < size; i++)
		outFile << wordList[i].word << " " << wordList[i].count << endl;

	outFile.close();

	cout << "Creating " << fileName << " . . .   done!" << endl;
}

/**  
  *   @brief  displays output to the user  
  *
  *	  @param counter is a reference integer variable that stores the current
  *		iteration of the function
  *   @return void  
  */ 
void display(int& counter)
{
	switch(counter)
	{
		case 0:
			cout << "Read text file" << endl;
			break;
		case 1:
			int k = 0;				///< Counter variable used for styling
			while (k < 47)
			{
				cout << "-";
				k++;
			}
			cout << endl << "Create frequency file" << endl;
			break;
	}

	counter++;
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