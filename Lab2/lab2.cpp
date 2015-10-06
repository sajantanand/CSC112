/** 
 *  @file    lab2.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    2/3/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 2, simulates games of craps
 *
 *  @section DESCRIPTION
 *  
 *  This program determines number of craps games to be played and
 *	then simulates the results of each game as well as the overall 
 *	win/loss record and win percentage.
 *
 */

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


void inputNumberOfGames(int& gamesToPlay);
int rollDie();
bool playGame(int& rolls);
int outputGameResult(int rolls, bool win, int counter);
void outputGameStats(int gamesWon, int gamesTotal);

/** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @param void
  *   @return int - used as a status indicator
  */  
int main()
{
	int games = 0;			///< Number of games to be simulated
	int rollsUsed = 0;		///< Roles needed to finish a game
	bool result = NULL;		///< Whether a game is win or loss
	int wins = 0;			///< Number of wins

	int i = 0;			///< Counter for 'for' loop
	
	inputNumberOfGames(games);
	
	for(i = 1; i <= games; i++)
	{
		result = playGame(rollsUsed);
		wins += outputGameResult(rollsUsed, result, i);		
	}

	outputGameStats(wins, games);		
}

/**
  *   @brief  Gets input from user (nuber of games to be played); also seeds
  *		random number generator used in rollDie()
  *  
  *   @param  gamesToPlay is an  reference integer variable used to hold number
  *		of games to be simulated
  *   @return void
  */
void inputNumberOfGames(int& gamesToPlay)
{		
	cout << "Enter the number of games to play -> ";
	cin >> gamesToPlay;
	srand (time(NULL));
}

/**
  *   @brief  Simulates rolling two dice using a random number generation
  *  
  *   @param  void
  *   @return int - sum of two randomly generated die; between 2 and 12
  */
int rollDie()
{
	int num1 = 0;			///< Holds first random number
	int num2 = 0;			///< Holds second random number
	rand();
	num1 = rand() % 6 + 1;
	rand();
	num2 = rand() % 6 + 1;	

	return num1 + num2;
}

/**
  *   @brief  Simulates a game of craps and returns number of rolls taken
  *		to finish the game and the outcome of the game (win/loss)
  *  
  *   @param  rolls is an reference integer variable used to hold number
  *		of rolls taken to finish the game
  *   @return bool - whether a game is a win/loss
  */
bool playGame(int& rolls)
{
	int twoDie = rollDie();		///< Holds the sum of rolling 2 die
	int point = 0;			///< Holds value of the 'Point'
	char status = 'u';		///< Represents status of game
	bool outcome;			///< Holds outcome of game; win/loss

	rolls = 1;
	
	

	if (twoDie == 7 || twoDie == 11)
	{
		status = 'C';
		outcome = true;
	}
	else if(twoDie == 2 || twoDie == 3 || twoDie == 12)
	{
		status = 'C';
		outcome = false;
	}
	else
	{
		while (!(status == 'C'))
		{
			point = twoDie;
			twoDie = rollDie();
			rolls++;

			if (twoDie == point)
			{
				outcome = true;
				status = 'C';
			}
			else if (twoDie == 7)
			{
				outcome = false;
				status = 'C';
			}		
		}
	}
	return outcome;
}

/**
  *   @brief  outputs result of one simulated game
  *  
  *   @param  rolls is an integer variable used to hold number
  *		of rolls taken to finish the game
  *	  @param  win is a boolean variable that holds outcome of the game
  *   @param  counter is an integer variable that tracks which game's results
  *		are being displayed
  *   @return int - 1 = Win, 0 = Loss
  */
int outputGameResult(int rolls, bool win, int counter)
{
	int result;			///< Holds result of game; 1 = win, 0 = loss

	if (win == true)
	{
		cout << "Game " << counter << " win, number of rolls " << rolls << endl;
		result = 1;
	}
	else
	{	
		cout << "Game " << counter << " lose, number of rolls " << rolls << endl;
		result = 0;
	}

	return result;
}

/**
  *   @brief  Outputs number of games won and win percentage for all the
  *		games that were simulated
  *  
  *   @param  gamesWon is an integer variable that holds number of games won
  *   @param  gamesTotal is an integer variable that holds total number
  *		of games
  *   @return void
  */
void outputGameStats(int gamesWon, int gamesTotal)
{
	double winPercentage = gamesWon/( (double) gamesTotal);
	cout << "Out of " << gamesTotal << " games, won " << gamesWon << " and lost " << (gamesTotal - gamesWon) << endl;
	cout << "Win percentage is " << winPercentage << endl;
}
