/******************************************************************************
 * CPSC230-TR					Fall 2019					Lab 8
 * Stefan Carlson
 * Reads a line of text from the user and prints out the number of occurrences of each letter
 *****************************************************************************/

/*
 * 1. Initialize key-value pair map to give each possible character an occurrence value
 * 2. Read input text and store to string
 * 3. For each character of input, find the key in the map and increment the occurrence value
 * 4.1. If it is whitespace, increment the number of words
 * 5. For each key, if the occurrence value is greater than 0, print the output
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	// Variables
	string input = "";
	int words = 1;
	map<char, int> chars;		// Stores every letter of the alphabet and a corresponding occurence value
	map<char, int>::iterator it;
	bool whitespace = false;		// True if the previous character was whitespace

	for (char c = 'a'; c <= 'z'; ++c)		// For ever letter of the alphabet
	{
		chars.insert(pair<char, int>(c, 0));		// Insert to pair and set occurrence value to 0
	}

	// Input
	cout << "Enter a line of text: \n";
	getline(cin, input);

	// Computation
	for (char c : input)
	{
		it = chars.find(tolower(c));		// Search for the key, which is the lowercase of c
		if (it == chars.end() && !whitespace)		// If map doesn't contain the key and this is the first of a set of whitespace
		{
			++words;
			whitespace = true;
		} else if (it != chars.end())		// If the map does contain the key (c is a letter)
		{
			++(it->second);
			whitespace = false;
		}
	}

	// Output
	if (words == 1)		// Because I'm a grammar nazi :p
		cout << "There is 1 word.\n";
	else
		cout << "There are " << words << " words.\n";

	for (pair<char, int> p : chars)		// For each pair in the chars map
	{
		if (p.second <= 0)		// Skip if zero occurrences
			continue;

		cout << p.second << " " << p.first << endl;		// Print line
	}
}
