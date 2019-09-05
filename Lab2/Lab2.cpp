//***********************************************************************************
//			CPSC 230 TR	Fall 2018			Lab 2A
// Stefan Lars Carlson
// Acceleration calculator: calculate acceleration required
// to achieve a certain velocity in a given time
//
//***********************************************************************************

/* Algorithm
1. Define variables (type double) vel, time, and accel
2. Define variable (type int) tempAccel
3. Define constant double MPH2MPS as 1609/3600
4. Display program name
5. Ask user for velocity, store to vel
6. Ask user for time, store to time
7. Calculate accel by dividing vel by time and multiplying the result by MPH2MPS
8. Multiply accel by 10
9. Add 0.5 to accel
10. Convert accel to 10 (will truncate decimal) and store to tempAccel
11. Convert tempAccel back to double and store to accel
12. Set cout precision to 2
13. Print accel to screen as final output
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
	double vel, time, accel;
	int tempAccel;
	const double MPH2MPS = 1609.0 / 3600.0;

	// Input
	cout << "~~ Acceleration Calculator! ~~\n\n" <<
		"Enter the final velocity in mph: ";
	cin >> vel;
	cout << "Enter the time in seconds: ";
	cin >> time;

	// Computation
	accel = MPH2MPS * (vel / time);
	accel *= 10;
	accel += 0.5;
	tempAccel = (int) accel;
	accel = static_cast<double> (tempAccel);
	accel /= 10;

	// Output
	cout << setprecision(2) << fixed;
	cout << "\nTo reach a velocity of " <<
		vel << " miles per hour in " << time << " seconds,\n" <<
		"you must have an acceleration of " <<
		accel << " meters per second.\n";

	return 0;
}
