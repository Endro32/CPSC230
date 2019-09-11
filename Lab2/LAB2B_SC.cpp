//******************************************************************************
// CPSC 230 TR				2019			Lab # 2B
// Stefan Carlson
// Takes two grade inputs in percentages, converts them both to letter grades,
// then compares the two to see who got the higher score
//******************************************************************************

// Using Linux kernel coding style

/* Algorithm:
1. Declare variables yourletter, theirletter that hold a single character each.
2. Declare variables yourgrade, theirgrade that hold whole numbers.
3. Prompt
4. Read.
4A  Convert percentage into single digit
5. Run code two times to get the values of yourgrade and theirgrade and assign the letters to yourletter and theirletter respectively.
6. 	If yourletter = ‘E’ or theirletter = ‘E’
		Print on the screen "Invalid input data, cannot determine who did better in the test!"
		Stop the program returning a 1.
	otherwise if yourletter  is less than theirletter
		Print on the screen "You did better in the test, you need to help your partner"
	otherwise if yourletter is more than theirletter
		Print on the screen "Your partner did better in the test, he needs to help you"
	otherwise
		Print on the screen "There is no winner!"
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	// Variables
	char yourLetter, theirLetter, repeat;
	int yourGrade, theirGrade;
	bool cont = true; // Short for continue, which is obviously an illegal name

	// Input
	cout << "Enter your grade as a percentage from 0-100: ";
	cin >> yourGrade;

	// Computation & Output
	// Correct input is an int between 0 & 100
	// Start by weeding out invalid input
	if (yourGrade >= 0 && yourGrade <= 100) {
		yourGrade /= 10;

		// Get a char based on percent grade
		if (yourGrade >= 9) {
			yourLetter = 'A';
		}
		else if (yourGrade == 8) {
			yourLetter = 'B';
		}
		else if (yourGrade == 7) {
			yourLetter = 'C';
		}
		else if (yourGrade == 6) {
			yourLetter = 'D';
		}
		else {
			yourLetter = 'F';
		}

	} else { // Invalid input
		yourLetter = 'E';
	}
	cout << "Your letter grade is: " << yourLetter << endl;

	// This is where the loop will begin (part B)
	while (cont) {
		cout << "Enter your friend's grade as a percentage from 0-100: ";
		cin >> theirGrade;

		// Same as for yourGrade
		if (theirGrade >= 0 && theirGrade <= 100) {
			theirGrade /= 10;

			// Get a char based on percent grade
			if (theirGrade >= 9) {
				theirLetter = 'A';
			}
			else if (theirGrade == 8) {
				theirLetter = 'B';
			}
			else if (theirGrade == 7) {
				theirLetter = 'C';
			}
			else if (theirGrade == 6) {
				theirLetter = 'D';
			}
			else {
				theirLetter = 'F';
			}

		} else { // Invalid input
			yourLetter = 'E';
		}
		cout << "Their letter grade is: " << theirLetter << endl;

		// Now that both grades have been converted to letters, we'll commpare them
		if (yourLetter == 'E' || theirLetter == 'E') {
			cout << "\nInvalid input data, cannot determine who did better in the test!";
			return 1;
		} else if (yourLetter < theirLetter) {
			cout << "\nYou did better in the test, you need to help your partner";
		} else if (yourLetter > theirLetter) {
			cout << "\nYour partner did better in the test, he needs to help you";
		} else { // Will occur if both letter grades are the same
			cout << "\nThere is no winner!\n";

			// Part C
			if (yourLetter == 'F') {
				// Linus Torvalds would be pissed that I'm 4 indents over
				cout << "Have you considered another major?";
			} else if (yourLetter == 'D') {
				cout << "Both should improve to avoid seeing me again next semester!";
			} else if (yourLetter == 'C') {
				cout << "Not bad but could be better";
			} else { // Will occur if the letter is an A or B
				cout << "Both did very good, congratulations!";
			}
		}

		// Ask if user wants to compare with another student
		cout << "\nWould you like to compare with another student? [Y/n]: ";
		cin >> repeat;

		// Unless user enters yes, exit the  program
		if (tolower(repeat) != 'y') {
			cont = false;
		}

	}

	// Just a nice little spacer there at the end
	cout << endl;
	return 0;
}
