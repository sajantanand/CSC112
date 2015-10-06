#include <iostream>
#define MAX_SIZE 100  
using namespace std;

void storeValue(int num, int a[], int& n);  

int main()
{
   int list[MAX_SIZE];  ///< list of positive ints 
   int n = 0;           ///< number of ints in list
   int num;             ///< value entered by the user
   
   cout << "Enter a number (negative to quit) -> ";
   cin >> num;
   while(num >= 0)  
   {  
      storeValue(num, list, n);  
      cout << "Enter a number (negative to quit) -> ";   
      cin >> num;
   }  

   // now you print the list in reverse order 
   
   return 0;
}

void storeValue(int num, int a[], int& n)
{

}  

