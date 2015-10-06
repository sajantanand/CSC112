#include <iostream>  
#include <string.h>  
#define MAX_SIZE 20   
using namespace std;  

bool getString(char str[]);  
bool reverso(char str[]);  

int main()  
{  
   char str[MAX_SIZE];  
   char strCpy[MAX_SIZE];  

   getString(str);  

   // copy str to strCpy 
   strcpy(strCpy, str); 

   if(reverso(strCpy)) 
   		cout << str << " reversed is " << strCpy << '\n';
   	else
   		cout << "No string entered to be reversed" << '\n';

   return 0;  
}  


bool getString(char str[])  
{  
   cout << "Enter a string -> ";  
   cin.getline(str, MAX_SIZE, '\n');

   // return true if a string was entered  
   return strlen(str) > 0;  
}  


bool reverso(char str[])  
{  
   bool reversed = false;  

   // return true if str reversed
   char temp;

   for (unsigned int i = 0; i < strlen(str)/2; i++)
	{
		temp = str[i];
		str[i] = str[strlen(str) - 1 - i];
		str[strlen(str) - 1 - i] = temp;
		reversed = true;
	}
	return reversed;  
} 


