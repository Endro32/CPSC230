/*
Stefan Carlson
Soft Drink Profit Program
*/

#include <iostream>

using namespace std;

int main1()
{
	int casesSoldDaily;

	cout << "How many cases do you sell daily?\n";
	cin >> casesSoldDaily;

	double dailyProfit = casesSoldDaily * 2.4;
	double annualProfit = dailyProfit * 365;

	cout << "You will earn $";
	cout << dailyProfit;
	cout << " in one day.\n You will earn $";
	cout << annualProfit;
	cout << " in one year.";
	
	return 0;
}