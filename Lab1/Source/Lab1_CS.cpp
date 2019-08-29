/*
Stefan Carlson
Soft Drink Profit Program
*/

#include <iostream>

using namespace std;

int main1()
{
	int casesSoldDaily;
	double profitPerBottle = .2;

	cout << "How many cases do you sell daily?\n";
	cin >> casesSoldDaily;

	double dailyProfit = casesSoldDaily * profitPerBottle * 12;
	double annualProfit = dailyProfit * 365;

	cout << "You will earn $";
	cout << dailyProfit;
	cout << " in one day.\n You will earn $";
	cout << annualProfit;
	cout << " in one year.";
	
	return 0;
}