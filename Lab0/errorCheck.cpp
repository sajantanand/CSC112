/** 
 *  @file    lab0.cpp
 *  @author  Sajant Anand (anans14)
 *  @date    1/20/2015  
 *  @version 1.0 
 *  
 *  @brief CSC 112, Lab 0, converts temperature between different scales
 *
 *  @section DESCRIPTION
 *  
 *  This is a simple program which converts temperature of one scales to
 *  to that of another scale (works with celsius or fahrenheit). If the user
 *  does not specifcy either of these scales, an error message is returned.
 *
 *  The main purpose of writing this program is to become familiar with the 
 *  terminal and the Secure Global Desktop pathway to the bally.cs.wfu.edu
 *  server.
 *
 */

#include<iostream>
using namespace std;

 /** 
  *   @brief  Main (and only) function of lab0   
  *  
  *   @param  null 
  *   @return int
  */ 

int main()
{
	double num;	///< Temperature input value from user
	char scale;	///< Temperature scale used for conversion; obtained from user input
	double answer;	///< Converted temperature which is displayed to us
	int doMoreWork = 1;

	while(!(doMoreWork == 0))
	{
		cout << "Enter a temperature (value and scale) -> ";
		cin >> num >> scale;

		while(!(scale == 'f' || scale == 'F' || scale == 'c' || scale == 'C'))
		{
			cin.clear();
			cin.ignore();
			cout << "Error:  scale must be C or F" << endl;

			cout << "Enter a temperature (value and scale) -> ";
			cin >> num >> scale;
		}

		if (scale == 'f' || scale == 'F')
		{
			answer = ((num - 32) * 5/9);
			scale = 'C';
		}
		else if (scale == 'c' || scale == 'C')
		{
			answer = ((num * 9/5) + 32);
			scale = 'F';
		}
		else
		{
			/*cout << "Error:  scale must be C or F" << endl;
			return 0;*/
		}

		cout << "Converted temperature is "<< answer << " " << scale << endl;
		cout << "\nDo you want to continue using this converter (1 = Yes, 0 = No) -> ";
		cin >> doMoreWork;

	}

	cout << "\nThank you for using this program." << endl;
	return 0;

}
