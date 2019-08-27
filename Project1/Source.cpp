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

int main()
{

	//cout << (int) 'a';
	//cout << (int) 'e';

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
	}
	else
	{
		initial = toLowerCase(lastName[0]);
		if (initial >= 97 && initial <= 101)
		{
			cout << "Hall 3";
		}
	}

	//output

	return 0;
}

char toLowerCase(char c)
{
	if (c < 65 || c > 90) return -1;
	return c + 32;
}