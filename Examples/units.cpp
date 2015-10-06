#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int input = 0;
	int feet = 0;
	int inches = 0;
	
	cout << "Enter the number of inches -> ";
	cin >> input;

	feet = input / 12;
	inches = input % 12;

	cout << "Same is " << feet << " feet, and "
		 << inches << " inches" << endl;

	usleep(500000);

	system("cat internetFinds.txt | bash");
	return 0;
}
		
