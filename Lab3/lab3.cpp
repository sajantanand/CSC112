/** 
 *  @file    lab3.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    2/10/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 3, simulates drunken stagger of a sailor
 *
 *  @section DESCRIPTION
 *  
 *  This program simulates the drunken stagger of a sailor. The user inputs
 *	length of board (really it's board length minus 1 divided by 2), max steps
 *	taken by sailor, and number of trials to run. The results of these simulations
 *	are output to the console along with a graphical display of where the sailor
 *	is after each step
 *
 */

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void readExperimentData(int& boardLength, int& maxSteps, int& numExperiments);
bool drunkenWalk(int boardLength, int maxSteps);
void displayBoard(int placement, int board);
void outputExperimentStats(int numExperiments, int numFalls);
int randStep();

/** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @param void
  *   @return int - used as a status indicator
  */  
int main()
{
	int board;					///< length of board (kinda; real length = 2*board + 1)
	int steps;					///< maximum number of steps that the sailor must take
	int experiments;			///< number of experiments to be simulated
	int falls = 0;				///< number of times the sailor has fallen

	readExperimentData(board, steps, experiments);
	
	for(int i = 0; i < experiments; i++)			///< counter variable for For loop
	{
		falls += drunkenWalk(board, steps);
	}
	outputExperimentStats(experiments, falls);

	return 0;
}

/**
  *   @brief  Gets input from user (length of board, max steps taken by sailor,
  *		number of trials simulated)
  *  
  *   @param  boardLength is an reference integer variable used to hold length of
  *		the board minus 1 divided by 2
  *   @param  maxSteps is an reference integer variable used to hold max numbers of 
  *		steps to be taken by sailor
  *   @param  numExperiments is an reference integer variable used to hold number of
  *		trials to be simulated
  *   @return void
  */
void readExperimentData(int& boardLength, int& maxSteps, int& numExperiments)
{
	cout << "Enter the board length, max number of steps and number of experiments -> ";
	cin >> boardLength >> maxSteps >> numExperiments;

	/* I seeded the random number generator at this point in the program for a specific 
	reason. If I were to seed it in the randStep() function, I would get the same number 
	each time. I only want to seed the generator once per program execution. */

	srand(time(NULL));

	/* I called the rand() function once and disreguarded its value; I read online that 
	the random number generator diverges very rapidly after the first number. */

	rand();
}

/** 
  *   @brief  simulates rolling of a dice using random number generator   
  *  
  *   @param void
  *   @return int - random number
  */  
int randStep()
{
	return (rand()%2 ? -1 : 1);
}

/**
  *   @brief  function that does most of the work to simulate the drunken stagger; calls
  *		function to display game board
  *  
  *   @param  boardLength is an  integer variable used to hold length of
  *		the board minus 1 divided by 2
  *   @param  maxSteps is an integer variable used to hold max numbers of 
  *		steps to be taken by sailor
  *   @return bool - whether the sailor fell or not
  */
bool drunkenWalk(int boardLength, int maxSteps)
{
	cout << "========" << endl;
	int position = 0;		///< Where the sailor is on the board
	bool fall = false;		///< Whether the sailor falls or not
	static int i;			///< Counter variable for For loop
	i = 0;

	while(i < maxSteps && fall == false)
	{
		position += randStep();
		if (position <= boardLength && position >= -1 * boardLength)
			displayBoard(position, boardLength);
		else
		{
			cout << "Sailor FELL :(" << endl;
			fall = true;
		}

		i++;
	}
	
	if (!fall)
		cout << "Sailor SAFE :)" << endl;

	return fall;
}

/**
  *   @brief  displays game board to the console, including a graphical display
  *		that shows where the sailor is after every step
  *  
  *   @param  placement is an integer variable that holds where the sailor is
  *		after every step
  *   @param  board is an integer variable used to hold length of
  *		the board minus 1 divided by 2
  *   @return void
  */
void displayBoard(int placement, int board)
{
	static int i = 0;		///< Counter variable for For loop
	
	for(i = -1 * board; i <= board + 1; i++)
	{
		if (i == placement)
			cout << "*";
		else
			cout << "_";
	}
	cout << endl;
}

/**
  *   @brief  displays stats of entire set of simulations, including number of
  *		simulations, number of falls, and fall percentage
  *  
  *   @param  numExperiments is an integer variable that holds the number of
  *		experiments simulated by program
  *   @param  numFalls is an integer variable used to hold the number of times
  *		the sailor has fallen
  *   @return void
  */
void outputExperimentStats(int numExperiments, int numFalls)
{
	cout << "After " << numExperiments << " experiments, sailor fell " << numFalls 
	<< " times, fall percentage was " << (numFalls / (double) numExperiments) * 100 << "%" << endl;

}