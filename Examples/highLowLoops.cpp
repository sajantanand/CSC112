#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void getInput(int& userInput);

int main()
{
	srand(time(NULL));	
	int answer = (rand() % 10) + 1;
	int guess = -1;

	getInput(guess);

	while (guess != answer)
	{
		if (guess > answer)
		{
			cout << "You guess too  high. Try again." << endl;
		}
		else
		{
			cout << "You guess too low. Try again." << endl;
		}

		getInput(guess);
	}


	cout << "Congratulations! You guessed correctly!" << endl;
	
	return 0;
}

void getInput(int& userInput)
{
	cout << "Please enter your guess -> ";
	cin >> userInput;
}
