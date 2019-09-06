//******************************************************************************
// CPSC 230 TR				2019			Lab # 2B
// Stefan Carlson
// Takes two grade inputs in percentages, converts them both to letter grades,
// then compares the two to see who got the higher score
//******************************************************************************

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char toLetter(int percent);

int main()
{
	// Variables
	char yourLetter, theirLetter, repeat;
	int yourGrade, theirGrade;

	// Input
	cout << "Enter your grade as a percentage from 0-100: ";
	cin >> yourGrade;

	// This is where the loop will begin
	while (true)
	{
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
			cout << "\nThere is no winner!\n";

			// Part C
			if (yourLetter == 'F')
			{
				cout << "Have you considered another major?";
			}
			else if (yourLetter == 'D')
			{
				cout << "Both should improve to avoid seeing me again next semester!";
			}
			else if (yourLetter == 'C')
			{
				cout << "Not bad but could be better";
			}
			else { // Will occur if the letter is an A or B
				cout << "Both did very good, congratulations!";
			}
		}

		// Ask if user wants to compare with another student
		cout << "\nWould you like to compare with another student? [Y/n]: ";
		cin >> repeat;

		// Unless user enters yes, exit the  program
		if (tolower(repeat) != 'y')
		{
			break;
		}

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