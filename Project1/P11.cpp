/*
Stefan Carlson
Soft Drink Profit Program
*/

#include <iostream>

using namespace std;

int main()
{
	int casesSoldDaily;
	double profitPerBottle = .22;

	cout << "How many cases do you sell daily?\n";
	cin >> casesSoldDaily;

	int bottlesSoldDaily = casesSoldDaily * 12;
	double dailyProfit = bottlesSoldDaily * profitPerBottle;
	double annualProfit = dailyProfit * 365;
	double tenYearProfit = annualProfit * 10;

	cout << "You will sell ";
	cout << bottlesSoldDaily;
	cout << " and earn $";
	cout << dailyProfit;
	cout << " in one day.\nYou will earn $";
	cout << annualProfit;
	cout << " in one year.\nYou will earn $";
	cout << tenYearProfit;
	cout << " in ten years.";
	
	return 0;
}