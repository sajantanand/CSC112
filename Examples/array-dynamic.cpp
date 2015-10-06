#include <iostream> 
using namespace std;

int* storeValue(int num, int *a, int& n); 
void printList(int a[], int n);

int main()
{
   int *list = NULL;  	///< list of positive ints 
   int n = 0;           ///< number of ints in list
   int num;             ///< value entered by the user
   
   cout << "Enter a number (negative to quit) -> ";
   cin >> num;
   while(num >= 0)  
   {
   	  //cout << list << endl;
      list = storeValue(num, list, n);
      //cout << list[n-1] << endl;
      cout << "Enter a number (negative to quit) -> ";   
      cin >> num;
   }  

   printList(list, n);
   // now you print the list in reverse order 
   
   return 0;
}

int* storeValue(int num, int *a, int& n)
{
	/*int *list = new (nothrow) int[n+1];

	for (int i = 0; i < n; i++)
	{
		// *(list + i) = *(a + i);
		list[i] = a[i];
	}
	list[n] = num;
	n++;

	if(a)
	{
		delete [] a;
	}

	a = list;*/

	int *list = new (nothrow) int[n+1];

	for (int i = 0; i < n; i++)
	{
		*(list + i) = *(a + i);
	}

	*(list + n) = num;
	n++;

	if(a)
	{
		delete [] a;
	}

	//a = NULL;

	return list;
} 

void printList(int a[], int n)
{
	for (int i = n -1; i > -1; i--)
	{
		cout << a[i] << endl;
	}
} 

