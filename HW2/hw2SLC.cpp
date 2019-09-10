//***************************************************************************
// CPSC 230		2019	 Homework # 2
// Stefan Carlson
// Generates a random number and gives the user five tries to guess that number
// 
//**************************************************************************/

/* Algorithm given in multiline comments */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Seed random
	/* Set random seed */
	srand(time(NULL));
	
	// Variables
	/* Create three integer variables:
	   - in: used to hold user input
	   - i: loop counter
	   - random: holds the randomly generated number the user is trying to guess */
	int in, i = 0, random = (rand() % 50) + 1;

	// Computation & Output
	/* Start loop. Increment i by 1 on each iteration. After 5 iterations, end loop */
	for (i; i < 5; i++) {
		/* Request user input and store to 'in' */
		cout << "Enter a number  between 1 & 50: ";
		cin >> in;
		if (in > random) { /* Tell user if they guess too high */
			cout << "Your number is too high.\n";
		} else if (in < random) { /* Tell user if they guess too low */
			cout << "Your number is too low.\n";
		} else if (in == random) { /* If user guesses random number, tell they they won and end the program */
			cout << "Congratulations, you win!";
			return 0;
		} else { /* Should never happen */
			cout << "You broke it :p";
			return 1;
		}
	}

	/* If the code reaches this point, the user has failed to guess the value in 5 tries
	   Tell themm they lose and end the program */

	cout << "You lose :(";
	return 0;

}