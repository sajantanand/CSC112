/** 
 *  @file    lab1.cpp
 *  @author  Sajant Anand (anans14)
 *  @date    1/27/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 1, processes light bult order
 *
 *  @section DESCRIPTION
 *  
 *  This is a little program that reads a number of light bulbs 
 *  to be ordered, calculates the number of various sized boxes,
 *  and computes the total cost of the order. This information is 
 *  then clearly displayed to the user.
 *
 */

#include<iostream>
using namespace std;

void inputOrder(int& number);

void calcOrder(int number, int& huge, int& large, int& medium, int& small,
	 double& costLB, double& costBox);

void outputOrder(int number, int huge, int large, int medium, int small,
	double costLB, double costBox);

 /** 
  *   @brief  main fuction of program, controlls execution   
  *  
  *   @return void
  */  
int main()
{
	int numOfBox = 0;		///< Number of light bulbs in order
	int numHuge = 0;		///< Number of huge boxes needed
	int numLarge = 0;		///< Number of large boxes needed
	int numMedium = 0;		///< Number of medium boxes needed
	int numSmall = 0;		///< Number of small boxes needed
	double costOfLB = 0.0;		///< cost of lightbulbs
	double costOfBox = 0.0;		///< cost of boxes

	inputOrder(numOfBox);
	calcOrder(numOfBox, numHuge, numLarge, numMedium, numSmall,
		 costOfLB, costOfBox);
	outputOrder(numOfBox, numHuge, numLarge, numMedium, numSmall,
		 costOfLB, costOfBox);
	return 0;
}

/** 
  *   @brief  Gets input from user (nuber of light bulbs in order)
  *  
  *   @param  number is an initialized reference integer variable, used to hold number
  *		of light bulbs in order
  *   @return void
  */  

void inputOrder(int& number)
{
	cout << "\nEnter the number of light bulbs in the order -> ";
	cin >> number;
}

/** 
  *   @brief  calculates number of differently sized boxes needed based on
  *		number of light bulbs in order
  *  
  *   @param  number is an initialized integer variable, used to hold number
  *		of light bulbs in order
  *   @param huge is an initialized reference integer variable to hold number
  *		 of huge boxes needed
  *   @param large is an initialized reference integer variable to hold number
  *		 of large boxes needed
  *   @param medium is an initialized reference integer variable to hold number
  *		 of medium boxes needed
  *   @param small is an initialized reference integer variable to hold number
  *		 of small boxes needed
  *   @param costLB is an initialized reference double variable to hold the cost
  *		 of light bulbs
  *   @param costBox is an initialized reference double variable to hold hte cost of boxes
  *   @return void
  */  
void calcOrder(int number, int& huge, int& large, int& medium, int& small,
	 double& costLB, double& costBox)
{
	int originalNumber = number;
	huge = number / 20;
	number %= 20;

	large = number / 15;
	number %= 15;

	medium = number / 7;
	number %= 7;

	small = number;

	costLB = originalNumber * 1.55;
	costBox = huge * 5.00 + large * 3.50 + medium * 2.00 + small * .75;
}

/** 
  *   @brief  displays order information to user, including number of each type
  *		of box needed, cost of light bulbs, cost of boxes, and total cost
  *  
  *   @param  number is an initialized integer  variable, used to hold number
  *		of light bulbs in order
  *   @param huge is an initialized integer variable to hold number
  *		 of huge boxes needed
  *   @param large is an initialized integer variable to hold number
  *		 of large boxes needed
  *   @param medium is an initialized integer variable to hold number
  *		 of medium boxes needed
  *   @param small is an initialized integer variable to hold number
  *		 of small boxes needed
  *   @param costLB is an initialized double variable to hold the cost
  *		 of light bulbs
  *   @param costBox is an initialized double variable to hold hte cost of boxes
  *   @return void
  */  
void outputOrder(int number, int huge, int large, int medium, int small,
	double costLB, double costBox)
{
	cout << "\nShipment Schedule for " << number << " Bulbs.\n" <<
		"-------------------------------\n" <<
		"Number of Container Required\n" <<
		"Huge	" << huge << "\n" <<
		"Large	" << large << "\n" <<
		"Medium	" << medium << "\n" <<
		"Small	" << small << "\n\n" <<
		
		"Cost of the light bulbs: $ " << costLB << "\n" <<
		"Cost of the containers:  $ " << costBox << "\n" <<
		"Total cost of the order: $ " << costBox + costLB << endl << "\n";
	
}
