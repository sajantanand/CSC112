/** 
*  @file fours.cpp
*  @date 2/28/2015  
* 
*  @brief array example
* 
*  @section DESCRIPTION  
*
*  This program should read and store into an array a list of
*  positive numbers. The program should print the list, remove all 4's
*  from the list, then print the list again
* 
*  more details here http://goo.gl/rxnHB1  
*
*/  

#include <iostream>  
#include <string.h>  
#define MAX_SIZE 20   
using namespace std;  

void getList(int list[], int& n);  
void printList(int list[], int n);  
bool removeFours(int list[], int& n);  

int main()  
{  
   int list[MAX_SIZE];  
   int n = 0;     ///< logical size  
   bool removed;

   getList(list, n);  

   printList(list, n);  

   removed = removeFours(list, n);  

   if(removed)  
      printList(list, n);  
   else
      cout << "List stays the same, but for something different go to http://goo.gl/rxnHB1 \n";

   return 0;  
}  


/**  
*  Read a list of positive ints from the user, negative to quit  
* 
*  @param  list[] list of positive ints, MAX_SIZE is phyiscal size  
*  @param  n logical size of list  
*  @return none  
*/  
void getList(int list[], int &n)  
{  

	cout << "Enter positive numbers (negative to stop)" << endl;

	int temp;
	cin >> temp;

	while (!(temp < 0) && n < MAX_SIZE)
	{
		list[n] = temp;
		n++;
		cin >> temp;
	}
}  


/**
* This function will remove all 4's from the list 
*
*  @param  list[] list of ints, MAX_SIZE is phyiscal size  
*  @param  n logical size of list  
*  @return true if any fours removed, false otherwise    
*/  
bool removeFours(int list[], int& n)  
{  
   bool removed = false;  ///< false is nothing removed 
   char fours[MAX_SIZE];
   int j = 0;

   for(int i = 0; i <= n; i++)
	{
		if (list[i] == 4)
		{
			fours[j] = i;
			j++;
		}
	}

	for(int i = --j; i >= 0; i--)
	{
		for(int k = fours[i]; k <= n; k++)
		{
			list[k] = list[k+1];
		}

		n--;
		removed = true;

	}
   return removed;  
}  


/**
* This function will print the contents of an array
*
*  @param  list[] list of ints  
*  @param  n logical size of list  
*  @return void      
*/  
void printList(int list[], int n)  
{  
	int i = 0;
   cout << '[';  
   for(i = 0; i < n - 1; i++)  
      cout << list[i] << ", ";  
   if(n > 0)  
      cout << list[i];  
   else  
      cout << "list is empty, but this ain't http://goo.gl/rxnHB1 ";  
   cout << "] \n";  
}   
   
