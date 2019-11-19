/*
 * HW67SC.cpp
 *
 *  Created on: Nov 12, 2019
 *      Author: webk7
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Calculates the statistical mean given a sum and number of elements of an array of integers
// Rounded to one decimal place
double mean(int sum, int elements);

// Returns a string with the specified number of spaces
string pad(int spaces);

const int MAX = 600;

int main()
{	// Variables
	ifstream inFile;
	ofstream outFile;

	string name[MAX];
	unsigned grade[MAX];

	unsigned quantity = 0, x = 0, sum = 0;
	double avg = 0.0;

	inFile.open("data7.txt");		// Open the data file
	if (!inFile.is_open())			// Check if the file didn't open
	{
		cerr << "File \"data7.txt\" failed to load\n";
		exit(1);
	}

	outFile.open("results.txt");

	while (!inFile.eof() && x < MAX)		// Read the data from the file into name[] and grade[]
	{
		inFile >> name[x];
		inFile >> grade[x];
		++x;
	}

	do		// Loop to repeat user input until valid
	{
		if (quantity != 0)		// If this isn't the first iteration of the loop
			cout << "Invalid index!\n";

		cout << "Enter quantity of grades to be processed (0 - " << x << "): ";
		cin >> quantity;
	} while (quantity > x);		// Checks to make sure the index is in range

	for (unsigned i = 0; i < quantity; ++i)		// For each element in the grade array
	{
		sum += grade[i];		// Add that grade to the sum
	}

	avg = mean(sum, quantity);		// Calculate mean
	cout << "The average grade is " << avg << endl;

	outFile << "Name                    Grade     Comment\n";

	string comment;
	unsigned spaces;
	for (unsigned i = 0; i < quantity; ++i)
	{
		outFile << name[i] << pad(24 - name[i].length()) << grade[i];

		if (grade[i] < 10)		// Figure out the padding between grade and comment
		{
			spaces = 9;
		} else if (grade[i] >= 100)
		{
			spaces = 7;
		} else
		{
			spaces = 8;
		}

		if (grade[i] > avg)		// Determine the comment
		{
			comment = "Above average";
		} else if (grade[i] == avg)
		{
			comment = "Average";
		} else		// Grade is below avg
		{
			comment = "Below average";
		}

		outFile << pad(spaces) << comment << endl;

	}

	cout << "Results.txt is done!\n";

}

double mean(int sum, int elements)
{
	if (sum < 0 || elements < 0)						// Exit if parameters are incorrect
	{
		cerr << "An internal error has occurred\n";
		exit(1);
	} else if (elements == 0)
	{
		return 0;
	}

	int avg = static_cast<double>(sum) / elements;		// Calculate the average
	return round(avg * 10) / 10;						// Round and return
}

string pad(int spaces)
{
	string ret(spaces, ' ');
	return ret;
}
