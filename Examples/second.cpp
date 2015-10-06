/** 
*  @file second.cpp
*  @date 2/28/2015  
* 
*  @brief array example
* 
*  @section DESCRIPTION  
*
*  This program should read and store into an array a list of
*  positive numbers from the user. The program should then
*  print the second largest value entered. 
* 
*  make certain to try {1, 2, 3}, {3, 2, 1} and {1, 1, 1}  
* 
*  more details here http://goo.gl/rxnHB1  
*
*/  

#include <iostream>  
#include <string.h>  
#define MAX_SIZE 20   
using namespace std;  

void getList(int list[], int& n);  
int secondLargest(int list[], int n); 
void printList(int list[], int size);  

int main()  
{  
   int list[MAX_SIZE];  
   int n = 0;     ///< logical size  
   int loc = -1;  ///< index of the second largest value  

   getList(list, n);  

   loc = secondLargest(list, n);  

   if(loc >= 0)  
      cout << "second largest value is " << list[loc] << '\n';  
   else
      cout << "There is no second largest, go to http://goo.gl/rxnHB1 for help \n";

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
   int temp;
   cin >> temp;
   while(!(temp < 0) && n < MAX_SIZE)
   {
      list[n++] = temp;
      cin >> temp;
   } 

   printList(list, n);
}  


/**
* This function will return the index of the second largest item 
*
*  @param  list[] list of ints, MAX_SIZE is phyiscal size  
*  @param  n logical size of list  
*  @return index of the second largest, -1 if it does not exist  
*/  
int secondLargest(int list[], int n)  
{  
   int sec = -1;  ///< location of second largest

   int pairs = n-1;
   bool done = false;
   while (!done)
   {
      done = true;
      for(int i = 0; i < pairs; i++)
      {
         if(list[i] > list[i+1])
         {
            int temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp;
            done = false;
         }
      }
      pairs--;
   } 

   sec = n-2;

   cout << sec << endl;
   return sec;  
}  

void printList(int list[], int size)
{
   cout << '[';
   for(int i = 0; i < (size - 1); i++)
      cout << list[i] << ", ";
   if ((size -1) >= 0)
   {
      cout << list[size-1];
      cout << ']' << '\n';
   }
   else
   {
      cout << "Nothing to see here!]" << '\n';
   }
} 


