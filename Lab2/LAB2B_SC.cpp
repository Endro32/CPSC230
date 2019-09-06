//******************************************************************************
// CPSC 230 TR/ MW		Semester Year		Lab # 2B
// Stefan Carlson
// Takes two grade inputs in percentages, converts them both to letter grades,
// then compares the two to see who got the higher score
//******************************************************************************

#include <iostream>

using namespace std;

char toLetter(int percent);

int main()
{
	// Variables
	char yourLetter, theirLetter;
	int yourGrade, theirGrade;

	// Input
	cout << "Enter your grade as a percentage from 0-100: ";
	cin >> yourGrade;
	cout << "Enter your friend's grade as a percentage from 0-100: ";
	cin >> theirGrade;

	// Computation
	yourLetter = toLetter(yourGrade);
	theirLetter = toLetter(theirGrade);

	// Output
	if (yourLetter == 'E' || theirLetter == 'E')
	{
		cout << "\nInvalid input data, cannot determine who did better in the test!";
		return 1;
	}
	else if (yourLetter < theirLetter)
	{
		cout << "\nYou did better in the test, you need to help your partner";
	}
	else if (yourLetter > theirLetter)
	{
		cout << "\nYour partner did better in the test, he needs to help you";
	}
	else
	{
		cout << "\nThere is no winner!";
	}

	// Just a nice little spacer there at the end
	cout << endl;
	return 0;
}

/*
* Takes a grade as a percent and returns a letter grade
* Returns E if percent is not between 0 and 100
*/
char toLetter(int percent)
{
	// Correct input is an int between 0 & 100
	// Start by weeding out invalid input
	if (percent >= 0 && percent <= 100)
	{
		percent /= 10;

		// Return a char based on percent grade
		if (percent >= 9)
		{
			return 'A';
		}
		else if (percent == 8)
		{
			return 'B';
		}
		else if (percent == 7)
		{
			return 'C';
		}
		else if (percent == 6)
		{
			return 'D';
		}
		else
		{
			return 'F';
		}
	} 

	// Invalid user input
	return 'E';
}