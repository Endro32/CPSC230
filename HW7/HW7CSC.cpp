/*******************************************************************
 * CPSC230 TR				Fall 2019					HW7C
 * Stefan Carlson
 * Reads a list of movies from a file and prints out all that made over $300 million.
 * User decides how many movies to process, then sum and average are calculated.
 * The top number of movies chosen by the user are printed to an output file
 *******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/* Calculates the statistical mean given a sum and number of elements of an array of integers
 * Rounded to one decimal place
 */
double mean(unsigned long sum, int elements);

// Prints the titles of each move that made at least 300 million. Assumes arrays are sorted
void print300(string *titles, int *profits);

// Returns a string with the specified number of spaces
string pad(int spaces);

const int MAX = 100;

int main()
{
	// Variables
	string title[MAX];
	int income[MAX];
	unsigned quantity = 0, x = 0;
	unsigned long sum;
	double avg;

	ifstream inMovie;
	inMovie.open("TopMovies.txt");

	ofstream outMovie;
	outMovie.open("TheBest.txt");

	if (inMovie.fail())		// If input file failed to load, exit program
	{
		cout << "TopMovies.txt failed to open\n";
		exit(1);
	}

	// Input
	string inc;		// Temporary income string

	while (!inMovie.eof() && x < MAX)		// Read up to 100 lines from the input file
	{
		getline(inMovie, title[x]);		// Read title line
		getline(inMovie, inc);		// Read income line
		income[x] = stoi(inc);		// Convert inc to int and store to income
		++x;
	}
	inMovie.close();		// Close the input file

	print300(title, income);		// Print movies that made over $300 million

	cout << "\nNow we will give you a list of top movies.\n"
		<< "Enter the quantity of movies to be processed (0 - " << x << "): ";
	cin >> quantity;

	for (unsigned i = 0; i < quantity && i < x; ++i)		// Will only process x elements if user entered higher value
	{
		sum += income[i];		// Add income to sum
	}
	avg = mean(sum, quantity);		// Calculate mean
	cout << "The average income is $" << avg << endl;		// Tell user the average

	outMovie << "Title                                                           "
			<< "Income          Comment\n";		// Output the header to the file

	for (unsigned i = 0; i < quantity && i < x; ++i)		// Will only process x elements if user entered higher value
	{
		string comment;
		if (income[i] > avg)		// Determine the comment
		{
			comment = "Above average";
		} else if (income[i] == avg)
		{
			comment = "Average";
		} else		// Grade is below avg
		{
			comment = "Below average";
		}

		outMovie << title[i] << pad(64 - title[i].length())		// Output the row for each movie
				<< income[i] << pad(16 - std::to_string(income[i]).length())
				<< comment << endl;
	}

	cout << "TheBest.txt is done!" << endl;

	return 0;
}

double mean(unsigned long sum, int elements) {
	if (elements < 0) {						// Exit if parameters are incorrect
		cerr << "An internal error has occurred\n";
		exit(1);
	}

	double avg = static_cast<double>(sum) / elements;		// Calculate the average
	return round(avg * 10) / 10;						// Round and return
}

void print300(string *titles, int *profits)
{
	cout << "The movies that made more than $300 million are:\n";
	for (int i = 0; i < MAX && profits[i] >= 300000000; ++i)
	{
		cout << titles[i] << endl;
	}
}

string pad(int spaces)
{
	string ret(spaces, ' ');
	return ret;
}
