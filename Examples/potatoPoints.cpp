#include <iostream>
using namespace std;

int main()
{
	int totalTime = 0;
	//int difference = 0;
	int pointsDifference = 0;
	//int applicableTime = 0;
	//int underflowTime = 0;
	//int timeBeforeFirstJob = 0;
	//int timeElapsed = 0;

	//cout << "Enter the seconds (after the potato was tossed) before first BJ ran -> ";
	//cin << timeBeforeFirstJob;	

	cout << "Enter the number of seconds since Potato was tossed -> ";
	cin >> totalTime;

	double pps1 = 25/60.0;
	double pps2 = pps1/2.0;
	double pps3 = pps2/2.0;
	double pps4 = pps3/2.0;
	double pps5 = pps4/2.0;
	
	if(totalTime <= 300)
		pointsDifference += totalTime * pps1;
	else
	{
		pointsDifference += 300 * pps1;
		if (totalTime <= 900)
			pointsDifference += (totalTime -300) * pps2;
		else
		{
			pointsDifference += 600 * pps2;
			if (totalTime <= 3600)
				pointsDifference += (totalTime - 900) * pps3;
			else
			{
				pointsDifference += 2700 * pps3;
				if(totalTime <= 21600)
					pointsDifference += (totalTime - 3600) * pps4;
				else
				{
					pointsDifference += 18000 * pps4;
					pointsDifference += (totalTime - 21600) * pps5;
				}
			}
		}
	}

	cout << "The total point difference over " << totalTime << " seconds is " << pointsDifference << " points." << endl;

	return 0;
}
