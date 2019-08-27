/*
Stefan Carlson
Starting Up
*/

#include <iostream>

using std::cin;
using std::cout;
using std::string;

char toLowerCase(char c);

int main()
{
	//vars
	string lastName;
	double balance;

	//input
	cout << ""


	//do stuff
	string x = "XHello";

	char y = x[0];
	cout << toLowerCase(y);

	//output

	//cout << (int) 'A';
	//cout << (int) 'Z';

	return 0;
}

char toLowerCase(char c)
{
	if (c < 65 || c > 90) return -1;
	return c + 32;
}