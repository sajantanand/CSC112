/** 
 *  @file    lab4.cpp
 *  @author  Sajant Anand (anans14) Section A
 *  @date    2/17/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 4, simulates drunken dancing of a sailor
 *
 *  @section DESCRIPTION
 *  
 *  This program simulates the drunken dancing of a sailor. The user inputs
 *	number of ex's present at dance, maximum number of steps to be taken by
 *	sailor, and a random seed that is used to generaate random numbers.
 *
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#define MAX_SIZE 10
using namespace std;

void getExperimentData(int& exes, int& moves, double& seedValue);
void setupDanceFloor(int exes, int floorBoard[][MAX_SIZE]);
void displayGameBoard(int floorBoard[][MAX_SIZE], int positionX, int positionY);
int simulateGame(int floorBoard[][MAX_SIZE], int moves, int& positionX, int& positionY, int& drama);
void displayGameResults(int positionX, int positionY, int current, int status);
void clearScreen();
int randStep();

/** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @param void
  *   @return int - used as a status indicator
  */ 
int main()
{
	int floor[MAX_SIZE][MAX_SIZE] = {};		///<Array that represents dance floor
	int numEx;								///<Number of ex's at dance
	int maxMoves;							///<Max number of steps by sailor
	double seed;							///<Number used to seed ran. numb. gen.
	int sailorX = 5;						///<Initial x-position of sailor
	int sailorY = 5;						///<Initial y-position of sailor
	int currentMoves;						///<Moves taken to find date or ex
	int result;								///<Whether sailor finds date, ex, or sleep
	
	clearScreen();

	getExperimentData(numEx, maxMoves, seed);
	srand(seed);							///<Seeds generator with user inputted number
	
	setupDanceFloor(numEx, floor);
	currentMoves = simulateGame(floor, maxMoves, sailorX, sailorY, result);
	displayGameResults(sailorX, sailorY, currentMoves, result);

	return 0;
}

/**
  *   @brief  Gets input from user (number of ex's, maximum steps taken by
  *		sailor, and number used to seed random number generator
  *  
  *   @param  exes is an reference integer variable used to hold number of exes
  *		present at the dance
  *   @param  moves is an reference integer variable used to hold max numbers of 
  *		steps to be taken by sailor
  *   @param  seedValue is an reference double variable used to hold a number
  *		used to seed random number generator.
  *   @return void
  */
void getExperimentData(int& exes, int& moves, double& seedValue)
{
	cout << "Enter the number of ex's, max number of moves, and random seed -> ";
	cin >> exes >> moves >> seedValue;
}

/**
  *   @brief  Gets input from user (number of ex's, maximum steps taken by
  *		sailor, and number used to seed random number generator
  *  
  *   @param  exes is an integer variable used to hold number of exes
  *		present at the dance
  *   @param  floorBoard is an (reference - by default) 2-D integer array used
  *		to represent the dance floor
  *   @return void
  */
void setupDanceFloor(int exes, int floorBoard[][MAX_SIZE])
{
	int row;					///<Holds row for placing exs and date
	int column;					///<Holds column for placing exs and date
	int i;						///<Loop counter variable
	
	for(i = 0; i < MAX_SIZE; i ++)
	{
		for(int j = 0; j < MAX_SIZE; j++)
			floorBoard[i][j]=0;
	}

	floorBoard[5][5] = 1;

	row = rand() % MAX_SIZE;
	column = rand() % MAX_SIZE;
	floorBoard[row][column] = -1;
	
	
	for(i = 0; i < exes; i++)
	{
		row = rand() % MAX_SIZE;
		column = rand() % MAX_SIZE;
		floorBoard[row][column] = -2;
	}
}

/**
  *   @brief  Simulates the movement of a sailor, tracks the sports that he has
  *		visited, and determines if he encounters a date or ex.
  *   
  *	  @param  floorBoard is an (reference - by default) 2-D integer array used
  *		to represent the dance floor
  *   @param  moves is an reference integer variable used to hold max numbers of 
  *		steps to be taken by sailor
  *   @param  positionX is an reference integer variable used to hold x-position
  *		of the sailor
  *   @param  positionY is an reference integer variable used to hold y-position
  *		of the sailor
  *   @return int - status of dance; 0 = sleep, 1 = date; 2 = ex
  */
int simulateGame(int floorBoard[][MAX_SIZE], int moves, int& positionX, int& positionY, int& drama)
{
	int current = 0;			///<Number of steps taken by sailor
	drama = 0;					///<Status of simulation; 0 = sleep, 1 = date; 2 = ex
	unsigned int microseconds = 500000;
	
	while (current < moves && drama == 0)
	{
		positionX += randStep();
		positionY += randStep();
		
		if (positionX < 0)
			positionX = 0;
		else if (positionX > 9)
			positionX = 9;
		
		if (positionY < 0)
			positionY = 0;
		else if (positionY > 9)
			positionY = 9;
		
		if (floorBoard[positionX][positionY] == -1)
			drama = 1;					//Found DATE
		else if (floorBoard[positionX][positionY] == -2)
			drama = 2;					//Found EX
		else
			floorBoard[positionX][positionY] ++;

		clearScreen();

		displayGameBoard(floorBoard, positionX, positionY);

		current++;
		usleep(microseconds);
	}
	
	return current;
}

/**
  *   @brief  Displays the floor board, where the sailor is, where the exs are
  *		where the date is, and how many times the sailor has visited each square
  *   
  *	  @param  floorBoard is an (reference - by default) 2-D integer array used
  *		to represent the dance floor
  *   @param  positionX is an integer variable used to hold x-position
  *		of the sailor
  *   @param  positionY is an integer variable used to hold y-position
  *		of the sailor
  *   @return void
  */
void displayGameBoard(int floorBoard[][MAX_SIZE], int positionX, int positionY)
{
	static int i = 0;			///<loop counter variable for rows
	static int j = 0;			///<loop counter variable for columns
	int characters = 0;			///<number of charters displayed for entry in array
	
	cout << "----------------------" << endl;
	
	for (i = 0; i < MAX_SIZE; i++)
	{
		cout << "|";
		
		for (j = 0; j < MAX_SIZE; j++)
		{

			characters = 0;

			if (i == positionX && j == positionY)
			{
				cout << "*";
				characters ++;
			}
			
			if (floorBoard[i][j] == -1)
			{
				cout << "$";
				characters++;
			}
			else if (floorBoard[i][j] == -2)
			{
				cout << "X";
				characters++;
			}
			else if (floorBoard[i][j] == 1)
			{
				cout << ".";
				characters++;
			}
			else if (floorBoard[i][j] == 2)
			{
				cout << ":";
				characters++;
			}
			else if (floorBoard[i][j] > 2)
			{
				cout << "@";
				characters++;
			}
			else
			{
				cout << " ";
				characters++;
			}
			
			if (characters == 1)
				cout << " ";
		}
		
		cout << "|" << endl;

	}
	
	cout << "----------------------" << endl;
}

/**
  *   @brief  displays the result of the simulation: whether the sailor finds
  *		date/ex/loneliness, how many moves it take, and where the final position
  *		of the sailor is
  *   
  *   @param  positionX is an integer variable used to hold x-position
  *		of the sailor
  *   @param  positionY is an integer variable used to hold y-position
  *		of the sailor
  *	  @param  current is an integer variable used to represent the number
  *		of steps taken by the sailor when the simulation ends
  *   @param  status is an integer variable used to hold result of simulation;
  *		2 = Ex, 1 = Date, 0 (default) = Falls asleep
  *   @return void
  */
void displayGameResults(int positionX, int positionY, int current, int status)
{
	std::string s0 ("");		///<String that holds the result of simulation
									
	switch(status)
	{
		case (2):
			s0 = "TEARS and DRAMA (ex)";
			break;
		case (1):
			s0 = "TRUE LOVE (date)";
			break;
		default:
			s0 = "LONELINESS and UNCONSCIOUSNESS (no one)";
	}

	cout << "Found " << s0 << " at (" << positionX << ", " << positionY << ") after " 
		<< current << " moves." << endl;	
}			
	
/** 
  *   @brief  uses random number generator to return either 1 or -1 
  *  
  *   @param void
  *   @return int - random number (1 or -1)
  */  
int randStep()
{
	//return (rand()%2 ? -1 : 1);
	return ((rand() % 3)-1);
}	

/**  
  *   @brief  clears an Xterm window  
  *
  *	  @param void
  *   @return void  
  */  
void clearScreen()
{
   //cout << char(27) << "[;H" << char(27) << "[2J" << '\n';
	system("clear");
}
