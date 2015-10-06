#include <iostream>  
#include <cstdlib>  
#include <string.h>
#include <cassert>
using namespace std;

bool removeNegative(int* &a, int &n);  
void printArray(int* a, int n);  

int main()  
{
   int n = 10;
   int* a = new (nothrow) int[n];  
   
   srand(time(0));  
   for(int i = 0; i < n; i++)  
   {
      a[i] = i;  
      if(rand()%2 == 0) a[i] *= -1;  
   }  
   
   printArray(a, n);  
   removeNegative(a, n);  
   printArray(a, n);  
   
   
   return 0;  
}  

bool removeNegative(int* &a, int &n)
{  
   bool removed = false;

   for(int i = n-1; i > -1; i--)
   {
      if(*(a + i) < 0)
      {
         for(int j = i + 1; j < n; j++)
            *(a + j - 1) = *(a + j);
         n--;

         removed = true;
      }
   }  

   if(n > 0)
   {
      int *temp = new (nothrow) int[n];
      assert(temp);

      memcpy(temp, a, n*4);

      if (a) { delete [] a;}

      a = temp;
   }

   // you complete this
   // for helpful hints see http://goo.gl/rxnHB1  

   return removed;
}  
  
void printArray(int* a, int n)
{  
   if(n > 0)  
   {  
      for(int i = 0; i < n; i++)  
         cout << a[i] << ' ';  
      cout << '\n';  
   }  
   else  
      cout << "empty list \n";  
}    

