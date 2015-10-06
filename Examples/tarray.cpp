#include <iostream>  
#include <cstdlib>  
using namespace std;

// your templates here...

<template TArray>
void printArray(TArray list[], int size)
{
   cout << "[";
   for(int i = 0; i < size; i++)
   {
      cout << list[i] << " ";
   }
   cout << "]";
}

<template TArray>
int maxValue(TArray list[], int size)
{
   int place = 0;
   int secondary = 0;

   for(int i = 1; i < size; i++)
   {
      if(list[i] > list[place])
      {
         place = i;
      }
      else if (list[i] < list[place])
      {
         secondary = i;
      }
   }

   if (secondary == place)
      place = -1;

   return place;
}

int main()  
{  
   int intList[10];  
   char charList[10];  

   srand(time(0));  
   
   for(int i = 0; i < 10; i++)  
   {  
      intList[i] = rand()%10;  
      charList[i] = (char)((int)'a' + rand()%26);  
   }  

   printArray(intList, 10);  
   printArray(charList, 10);  
   
   int maxInt = maxValue(intList, 10);  
   int maxChar = maxValue(charList, 10);  

   if(maxInt >= 0)  
      cout << "int: index of largest is " << maxInt << ", stores " << intList[maxInt] << '\n';  
   else  
      cout << "int: there is no maximum value \n";  

   if(maxChar >= 0)  
      cout << "char: index of largest is " << maxChar << ", stores " << charList[maxChar] << '\n';  
   else  
      cout << "char: there is no maximum value \n";  

   return 0;  
}


