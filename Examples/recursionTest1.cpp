#include<iostream>
using namespace std;

int recursion (float n);
float recursion1 (float n);

int main()
{
	float x = 5.0;
	
	x = recursion(5.0);	

	cout << x << endl << endl;

	x = 5.0;

	x = recursion1(5.00);

	cout << x << endl;
}

int recursion(float n)
{
	if (n < 0)
	{
		cout << n << endl;
		return n;
	}	
	else 
	{
		cout << n << endl;
		return n + recursion(n-1.5);
	}
}
float recursion1(float n)
{
	if (n < 0)
	{
		cout << n << endl;
		return n;
	}	
	else 
	{
		cout << n << endl;
		return n + recursion(n-1.5);
	}
}
