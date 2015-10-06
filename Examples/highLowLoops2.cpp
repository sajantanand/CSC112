:#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int secret;
	int guess;

	srand(time(NULL));
	secret = rand();
	secret = rand() % 10 + 1;

	do {
		printf ("Guess the number (1 to 10): ");
		scanf ("%d",&guess);
		if (secret < guess) puts ("The secret number is lower.");
		else if (secret > guess) puts ("The secret number is higher.");
	} while (secret != guess);

	puts ("Congratulations!");
	return 0;
}

