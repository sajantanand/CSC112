#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void addChar(char member, char*& array, int& size);
void addInt(int member, int*& array, int& size);

int main()
{
	fstream inFile("triangle.txt", ios::in);		///< Initializes fstream
	//ifstream inFile("triangle.txt");		///< Initializes fstream


	char ch;
	int *ptr;
	char *cString;
	int number;

	int sizeCS = 0;
	int sizeINT = 0;

	ch = inFile.get();

	//getline(inFile, ch);

	while (!inFile.eof())
	{
		//cout << ch << endl;
		cout << "5" << endl;
		cout << "ch: " << ch << endl;

		if(isdigit(ch))
		{
			cout << "6" << endl;
			addChar(ch, cString, sizeCS);
			cout << "7" << endl;
			//cout << "called" << endl;
		}
		else if (cString)
		{
			number = atoi(cString);
			cout << "1" << endl;
			cout << "NUMBER: " << number << endl;
			cout << "2" << endl;
			//cout << "NUMBER: " << number << endl;
			addInt(number, ptr, sizeINT);
			delete cString;
			cout << "3" << endl;
			cString = 0;
			cout << "4" << endl;
			sizeCS = 0;
			number = 0;
		}


		ch = inFile.get();
	}

	addInt(number, ptr, sizeINT);

	for(int i = 0; i < sizeINT; i++)
	{
		cout << *(ptr + i) << endl;
	}


	inFile.close();

	return 0;
}

void addChar(char member, char*& array, int& size)
{
	if(array)
	{
		char* temp = new (nothrow) char[size+2];
		for(int i = 0; i < size; i++)
			temp[i] = *(array + i);

		temp[size] = member;
		temp[++size] = '\0';

		array = temp;

		temp = 0;	
	}
	else
	{
		array = new (nothrow) char[2];
		array[0] = member;
		array[1] = '\0';

		size = 1;
	}
}

void addInt(int member, int*& array, int& size)
{
	if(array)
	{
		int *temp = new (nothrow) int[size++];

		for(int i = 0; i < size; i++)
			temp[i] = *(array + i);
		temp[size] = member;
		size++;

		array = temp;

		temp = 0;
	}
	else
	{
		array = new (nothrow) int[1];
		array[0] = member;

		size = 1;
	}
}