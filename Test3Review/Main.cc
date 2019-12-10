/*
 * Main.cc
 *
 *  Created on: Dec 5, 2019
 *      Author: webk7
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Performs a bubble sort of the given int array
 */
void sort(vector<int> &vec);

int q3()
{
	string text = "Welcome! How is your day going?";
	string name, day;

	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter the day of the week: ";
	cin >> day;

	text.insert(20, " " + day);
	text.insert(7, ", " + name);

	cout << text;

	return 0;
}

int q4()
{
	string input;
	vector<int> v;
	int search;

	cout << "Type in as many numbers as desired. Type a letter to be done.\n";

	while (true)
	{
		cin >> input;
		try		// Attempt to convert input to integer and add to vector
		{
			v.push_back(stoi(input));
		}
		catch (const invalid_argument &ia)		// If user enters letters, be done
		{
			break;
		}
	}

	cout << "Now enter a number to search for: ";
	cin >> search;

	for (unsigned i = 0; i < v.size(); ++i)		// For each element in the vector
	{
		if (v[i] == search)		//  If element at index i is the same as what the user entered to search for
		{
			cout << "Found " << search << " at index " << i << endl;
		}
	}

	return 0;
}

int q8()
{
	int code, *ptr;
	cout << "Enter a secret number: ";
	cin >> code;
	ptr = &code;
	cout << ptr;
}

int q9()
{
	int in;
	vector<int> v;

	cout << "Enter 15 numbers:\n";
	for (int i = 0; i < 15; ++i)
	{
		cin >> in;
		v.push_back(in);
	}

	sort(v);
	v.resize(5);
	for (int n : v)
	{
		cout << n << endl;
	}

}

void sort(vector<int> &vec)
{
	int x, y;	// We'll move down on the y axis (passes), sorting through the array each time
	bool swapped = true;		// If no swaps are made during a pass, we'll stop sorting
	for (y = 0; y < vec.size() - 1 && swapped; ++y)		// Continue with new passes until the whole array is sorted
	{
		swapped = false;		// Reset swap test
		for (x = 0; x < vec.size() - y - 1; ++x)	// We'll skip the last 'y' elements since they're already sorted
		{
			if (vec[x] < vec[x + 1])		// If the element is less than the one immediately to the right
			{
				int temp = vec[x];		// Swap the elements
				vec[x] = vec[x + 1];
				vec[x + 1] = temp;
				swapped = true;		// The sort isn't done, so keep going
			}
		}
	}
}

int main()
{
	double value = 29.7;
	double *ptr = &value;
	cout << *ptr;
}

void getNumber (int *n)
{
	cout << "Enter a number:  ";
	cin >> *n;
}
