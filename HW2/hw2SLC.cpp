//***************************************************************************
// CPSC 230		2019	 Homework # 2
// Stefan Carlson
// Generates a random number and gives the user five tries to guess that number
// 
//**************************************************************************/

/* Algorithm
 * 1. Set random seed
 * 2. Create three integer variables:
 *	   - in: used to hold user input
 *	   - i: loop counter
 *	   - random: holds the randomly generated number the user is trying to guess
 * 3. Start loop. Increment counter (i) by 1 on each iteration. After 5 iterations, end loop
 * 4. On each loop:
 *     A. Request user input and store to 'in'
 *     B. If input is higher than the random value, tell the user they guessed too high
 *     C. If input is lower than the random value, tell the user they guessed too low
 *     D. If input is equall to the random value, tell the user they won
 *         End the program with code 0
 *     E. If none of these are the case (which should never happen), tell the user they broke it
 *         End the program with code 1
 * 5. If the loop ends, the user has not successfully guessed the number in five tries
 * 6. Tell them they lose
 *    End the program with code 0
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Seed random
	srand(time(NULL));
	
	// Variables
	int in, i = 0, random = (rand() % 50) + 1;

	// Computation & Output
	for (; i < 5; i++) {
		cout << "Enter a number  between 1 & 50: ";
		cin >> in;
		if (in > random) {
			cout << "Your number is too high.\n";
		} else if (in < random) {
			cout << "Your number is too low.\n";
		} else if (in == random) {
			cout << "Congratulations, you win!";
			return 0;
		} else { /* Should never happen */
			cout << "You broke it :p";
			return 1;
		}
	}

	// If the code reaches this point, the user has failed to guess the value in 5 tries
	// Tell them they lose and end the program

	cout << "You lose :(";
	return 0;

}
