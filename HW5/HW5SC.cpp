/*
 * CPSC230						Fall 2019						HW #5
 * Stefan Carlson
 * Asks the user to enter the two lengths for a rectangle and an ellipse.
 * It then prints out the respective areas of the two shapes
 */

#include <iostream>
#include <iomanip>

using namespace std;

void getData(double&, double&);
void printData(double rect, double elli);
double area_rectangle(double, double);
double area_ellipse(double, double);

const double PI = 3.141592;

int main()
{
	// Variables
	double base = 0, height = 0, recarea = 0;
	double radiusa = 0, radiusb = 0, elliarea = 0;

	// Intput
	cout << "For the rectangle:\n";
	getData(base, height);
	cout << "\nFor the ellipse:\n";
	getData(radiusa, radiusb);

	// Calculation
	recarea = area_rectangle(base, height);
	elliarea = area_ellipse(radiusa, radiusb);

	// Output
	printData(recarea, elliarea);

	return 0;
}

/**
 * Asks the user to enter two lengths and stores them to the two variables passed as parameters
 */
void getData(double &rpar1, double &rpar2)
{
	cout << "Please enter the first length: ";
	cin >> rpar1;
	cout << "Please enter the second length: ";
	cin >> rpar2;
}

/**
 * Prints to the screen the area of the rectangle and ellipse repsecitvely
 */
void printData(double rect, double elli)
{
	cout << showpoint << setprecision(1) << fixed;

	cout << "\nThe area of the rectangle is " << rect
		<< "\nThe area of the ellipse is " << elli;
}

/**
 * Computes the area of a rectangle with given length and width.
 * Returns area as a double
 */
double area_rectangle(double len, double wid)
{
	return len * wid;
}

/**
 * Computes the area of an ellipse with the specified radii.
 * Returns area as a double
 */
double area_ellipse(double rada, double radb)
{
	return PI * rada * radb;
}
