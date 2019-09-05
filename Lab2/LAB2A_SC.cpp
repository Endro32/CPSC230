//***********************************************************************************
//			CPSC 230 TR	Fall 2018			Lab 2A
// Stefan Lars Carlson
// Acceleration calculator: calculate acceleration required
// to achieve a certain velocity in a given time
//
//***********************************************************************************

// Algorithm
/*
1. Define variables (type double) v, t, and a
2. Define variable (type int) tempA
3. Define constant double MPH2MPS as 1609/3600
4. Display program name
5. Ask user for velocity, store to v
6. Ask user for time, store to t
7. Calculate a by dividing v by t and multiplying the result by MPH2MPS
8. Multiply a by 10
9. Add 0.5 to a
10. Convert a to 10 (will truncate decimal) and store to tempA
11. Convert tempA back to double and store to a
12. Set cout precision to 2
13. Print a to screen as final output
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main1()
{
    // Variables
	double v, t, a;
	int tempA;
	const double MPH2MPS = 1609.0 / 3600.0;

	// Input
	cout << "~~ Acceleration Calculator! ~~\n\n" <<
		"Enter the final velocity in mph: ";
	cin >> v;
	cout << "Enter the time in seconds: ";
	cin >> t;

	// Computation
	a = MPH2MPS * (v / t);
	a *= 10;
	a += 0.5;
	tempA = (int) a;
	a = static_cast<double> (tempA);
	a /= 10;

	// Output
	cout << setprecision(2) << fixed;
	cout << "\nTo reach a velocity of " <<
		v << " miles per hour in " << t << " seconds,\n" <<
		"you must have an acceleration of " <<
		a << " meters per second squared.\n";

	return 0;
}
