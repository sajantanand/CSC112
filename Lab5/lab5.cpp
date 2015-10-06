/** 
 *  @file    lab5.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    2/24/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 5, reads in text file and counts character usage
 *
 *  @section DESCRIPTION
 *  
 *  This program counts the number of each type of character used in a text
 *	file. We considered three distinct types: alpha characters (letters),
 *	digits (numbers), and other (everything else).
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_STRING_SIZE 20
#define MAX_LIST_SIZE 50
using namespace std;

/** 
  *   @brief  data structure used to create array; holds both the character
  *		and the number of times it has appeared in file 
  */ 
struct CharFreq
{
	char ch;			///< Unique character - either alpha, digit, or other
	int count;			///< Number of times characters occurs in file
};

void readFileName(char fileName[]);
bool addCharToList(char ch, CharFreq list[], int& num);
bool readFile(char fileName[], CharFreq alphaList[], int& alphaNum,
	CharFreq digitList[], int&digitNum, CharFreq otherList[], int& otherNum);
int search(char ch, CharFreq list[], int num);
void sort(CharFreq list[], int num);
void displayTopFive(CharFreq list[], int num, int status);
void clearScreen();

/** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @param void
  *   @return int - used as a status indicator
  */ 
int main()
{
	clearScreen();

	char nameOfFile[MAX_STRING_SIZE];	///< C-String to hold file name
	CharFreq listAlpha[MAX_LIST_SIZE];	///< CharFreq array to hold alpha chars
	CharFreq listDigit[MAX_LIST_SIZE];	///< CharFreq array to hold digit chars
	CharFreq listOther[MAX_LIST_SIZE];	///< CharFreq array to hold other chars

	for(int i = 0; i < MAX_LIST_SIZE; i++)	///Initialize count to 0 for each element
	{
		listAlpha[i].count = 0;
		listDigit[i].count = 0;
		listOther[i].count = 0;
	}

	int numAlpha = 0;		///< Number of unique alpha chars; size of array
	int numDigit = 0;		///< Number of unique digit chars; size of array
	int numOther = 0;		///< Number of unique other chars; size of array

	bool success;

	do {
		readFileName(nameOfFile);
		success = readFile(nameOfFile, listAlpha, numAlpha, listDigit, numDigit, listOther,
			numOther);
	} while (success != true);

	displayTopFive(listAlpha, numAlpha, 0);
	displayTopFive(listDigit, numDigit, 1);
	displayTopFive(listOther, numOther, 2);
	
	return 0;
}

/**
  *   @brief  Gets input from user (name of file to be parsed)
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to use
  *   @return void
  */
void readFileName(char fileName[])
{
	int i = 0;		///< Local loop variable
	char ch;		///< Holds each character as it is being read
	cout << "Enter the name of the text file -> ";
	
	ch = cin.get();
	while(ch != '\n' && ch != ' ' && i <( MAX_STRING_SIZE - 1))
	{
		fileName[i] = ch;
		ch = cin.get();
		i++;
	}

	fileName[i] = '\0';		///< Appends null terminator to C-String
	cout << endl;
}

/**
  *   @brief  Reads in each character of file sequentially so that it can
  *		be parsed correctly
  *  
  *   @param  fileName is an reference (by default) character array (C-String)
  *		that holds the name of file the user wishes to use
  *   @param  alphaList is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the letter characters and the
  *		number of times they have appeared
  *	  @param  alphaNum is a reference interger variable used to hold the number
  *		of distinct alpha characters; also is size of the array
  *   @param  digitList is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the digit characters and the
  *		number of times they have appeared
  *	  @param  digitNum is a reference interger variable used to hold the number
  *		of distinct digit characters; also is size of the array
  *   @param  otherList is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the other characters and the
  *		number of times they have appeared
  *	  @param  otherNum is a reference interger variable used to hold the number
  *		of distinct other characters; also is size of the array
  *   @return bool - whether file was read successfully or not
  */
bool readFile(char fileName[], CharFreq alphaList[], int& alphaNum,
	CharFreq digitList[], int&digitNum, CharFreq otherList[], int& otherNum)
{
	fstream inFile(fileName, ios::in);		///< Initializes fstream

	if(inFile.fail())
		return false;
	
	char ch;		///< Holds each character as it is being processed

	ch = inFile.get();
	while (!inFile.eof() && alphaNum < MAX_LIST_SIZE && digitNum < MAX_LIST_SIZE && otherNum < MAX_LIST_SIZE)
	{
		if(isalpha(ch))
			addCharToList(tolower(ch), alphaList, alphaNum);
		else if(isdigit(ch))
			addCharToList(ch, digitList, digitNum);
		else
			addCharToList(ch, otherList, otherNum);
		ch = inFile.get();
	}

	inFile.close();
	return true;
}

/**
  *   @brief  Either adds each character to the array passed into the 
  *		function or increments the number of occurances depending on if
  *		the character is already in the array
  *  
  *   @param  list is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the characters (type of character
  *		is determined by the actual arguements) and the number of times they
  *		have appeared
  *	  @param  num is a reference interger variable used to hold the number
  *		of distinct characters (same type as list); also is size of the array
  *   @return bool - whether character was processed successfully or not
  */
bool addCharToList(char ch, CharFreq list[], int& num)
{
	int loc = search(ch, list, num);	///< Position in array
	if (loc != -1)
	{
		list[loc].count++;
	}
	else if (num < MAX_LIST_SIZE)
	{
		list[num].ch = ch;
		list[num].count++;
		num++;
	}
	else
	{
		cout << "list out of space \n";
		return false;
	}

	return true;
}

/**
  *   @brief  Searches an array for a particular value and returns the
  *		location of value if present in array
  *  
  *   @param  target is an character variable that holds the character being
  *		searched for in the array; may be alpha, digit, or other
  *   @param  listToSearch is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the characters (type of character
  *		is determined by the actual arguements) and the number of times they
  *		have appeared
  *	  @param  size is a interger variable used to hold the number
  *		of distinct characters (same type as list); this is the size of the
  *		array
  *   @return int - location of target character in array; if target is not
  *		in array, returns -1
  */
int search(char target, CharFreq listToSearch[], int size)
{
	int location = -1;		///< Location of char in array
	int i = 0;				///< Local loop counter

	while(i < size && location == -1)
	{
		if(listToSearch[i].ch == target)
			location = i;
		i++;
	}
	return location;
}

/**
  *   @brief  sorts the array in descending order using inserion sort
  *  
  *   @param  list is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the characters (type of character
  *		is determined by the actual arguements) and the number of times they
  *		have appeared
  *	  @param  num is a interger variable used to hold the number
  *		of distinct characters (same type as list); also is size of the array
  *   @return void
  */
void sort(CharFreq list[], int num)
{
	CharFreq temp;		///< Dummy variable used to swap values
	int j;				///< Local loop counter

	for(int i = 1; i < num ; i++)
	{
		temp = list[i];

		for(j = i; j > 0 && temp.count > list[j - 1].count; j--)
			list[j] = list[j - 1];
		
		list[j] = temp;
	}
}

/**
  *   @brief  displays the 5 most common characters from each set (alpha,
  		digit, other); first sorts the array
  *  
  *   @param  list is an reference (by default) CharFreq array
  *		(user-defined type) that holds all the characters (type of character
  *		is determined by the actual arguements) and the number of times they
  *		have appeared
  *	  @param  num is a interger variable used to hold the number
  *		of distinct characters (same type as list); also is size of the array
  *   @param  status is an interger variable that conveys the tipe of character
  *   @return void
  */
void displayTopFive(CharFreq list[], int num, int status)
{
	sort(list, num);

	//std::string s0 ("");		///<String that holds the type of character
	char strl[6];			///< C-String used to hold type of character

	switch(status)
	{
		case (0):
			//s0 = "alpha";
			strl[0] = 'a';
			strl[1] = 'l';
			strl[2] = 'p';
			strl[3] = 'h';
			strl[4] = 'a';
			strl[5] = '\0';
			break;
		case (1):
			//s0 = "digit";
			strl[0] = 'd';
			strl[1] = 'i';
			strl[2] = 'g';
			strl[3] = 'i';
			strl[4] = 't';
			strl[5] = '\0';
			break;
		case (2):
			//s0 = "other";
			strl[0] = 'o';
			strl[1] = 't';
			strl[2] = 'h';
			strl[3] = 'e';
			strl[4] = 'r';
			strl[5] = '\0';
			break;
	}

	cout << strl << " top 5 out of " << num << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < 5; i ++)
		cout << "[" << list[i].ch << "] " << list[i].count << endl;
	cout << endl;
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