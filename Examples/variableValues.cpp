#include<iostream>
using namespace std;
double f(int &j, float &y, float x);
int main()
{
	int i,j;
	float x,y;
	j = y = i = x = 1/2.0;

	for(i=2; i < 4; i++)
		i *= 2;
	j = f(i, x, y);
	cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
	return 0;
}

double f(int &j, float &y, float x)
{
	int i = j;
	if (x <= y)
		x += 2;
	else
		x -= 2;
	return(y = int(x+0.5));
}
