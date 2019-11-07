/*****************************************************************************************
 * CPSC230						Fall 2019							Lab #6/7
 * Stefan Carlson
 * Reads a set of scores (up to 100) from Data.txt; calclates a total and an average.
 * Then prints each score and whether it was above or below average to Results.txt
 *****************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Prototypes
double mean(int sum, int elements);

// Constant
const int MAX = 100;

int main()
{
	// Variable
	int nums[MAX];			// T'was slightly painful to code this, since a vector would be much better
	int i = 0, sum = 0;
	double avg;

	ifstream inFile;
	inFile.open("Data.txt");

	ofstream outFile;
	outFile.open("Results.txt");

	if (inFile.fail())									// If input file failed to load, exit program
	{
		cout << "This file didn't open\n";
		exit(1);
	}

	// Input
	while (!inFile.eof() && i < MAX)					// Read up to 100 lines from the input file
	{
		inFile >> nums[i];								// Add value to array at current index
		sum += nums[i++];								// Add to sum and increment index
	}
	inFile.close();										// Close the input file

	// Calculation
	avg = mean(sum, i);

	// Output
	outFile << "Score\t\tAbove/Below Average\n";
	for (int n = 0; n < i; ++n)							// For each element in the array
	{
		cout << nums[n] << endl;						// Output on screen and to file
		outFile << nums[n] << "\t\t\t" << (nums[n] < avg ? "is below Average" : "is above Average") << endl;
	}

	outFile.close();									// Close the output file

}

// Calculates the statistical mean given a sum and number of elements of an array of integers
// Rounded to one decimal place
double mean(int sum, int elements) {
	if (sum < 0 || elements < 0) {						// Exit if parameters are incorrect
		cerr << "An internal error has occured\n";
		exit(1);
	}

	int avg = static_cast<double>(sum) / elements;		// Calculate the average
	return round(avg * 10) / 10;						// Round and return
}
