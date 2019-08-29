/*
Stefan Carlson
Starting Up
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

char toLowerCase(char c);

int main2()
{
	//vars
	string lastName;
	char initial;
	double balance;

	//input
	cout << "Enter your last name:\n";
	cin >> lastName;
	cout << "Enter your current balance:\n";
	cin >> balance;


	//do stuff
	if (balance == 0)
	{
		cout << "Hall 18";
		return 0;
	}
	else
	{
		initial = toLowerCase(lastName[0]);
		if (initial >= 97 && initial <= 101)
		{
			cout << "Hall 3";
			return 0;
		}
		else if (initial >= 102 && initial <= 106)
		{
			cout << "Hall 2";
			return 0;
		}
		else if (initial >= 107 && initial <= 111)
		{
			cout << "Hall 8";
			return 0;
		}
		else if (initial >= 112 && initial <= 114)
		{
			cout << "Hall 10";
			return 0;
		}
		else if (initial >= 1145 && initial <= 122)
		{
			cout << "Hall 12";
			return 0;
		}
	}

	//If the program reaches this far, the user entered invalid input
	return -1;
}

char toLowerCase(char c)
{
	//If the character is in the range of uppercase characters,
	//adding 32 to its binary representation will make it lowercase
	if (c < 65 || c > 90) return -1;
	return c + 32;
}