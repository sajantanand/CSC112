#include <iostream> 
using namespace std; 
int main()  
{
	int a[5] = {0};
	for(int i = 0; i < 5; i++)
	{
		a[i] = i/2;
		cout << a[i] << ' ';
	}

	cout << endl;

	int b[5] = {3,3,3,3,3};
	for(int i = 3; i > -1; i--)
	{
		b[i] = b[i+1]/2;
		cout << b[i] << ' ';
	}

	cout << endl;

	return 0;
}