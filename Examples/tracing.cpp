#include <iostream>
using namespace std;

void f(int a, int &b);
int main()
{
	int i = 1;
	int j = 2;
	bool x = (i/j > 0);
	
	if (x)
		f(i,j);
	else
	{
		int i = 3;
		f(j,i);
	}

	cout << i << ' ' << j << ' ' << x << '\n';
	return 0;
}

void f(int a, int &b)
{
	bool x = (a > b);
	if(x)
	{
		int a = b;
		b = a + b;
	}
}
