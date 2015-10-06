#include <cmath>
#include <iostream>

void printStuff(double);

int main()
{
	double x = sqrt(4);
	std::cout << x << std::endl;
	printStuff(x);

	return 0;
}

void printStuff(double toPrint)
{
	std::cout << toPrint << std::endl;
}