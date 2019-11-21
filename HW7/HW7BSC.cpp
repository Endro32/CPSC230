/***********************************************************************************
 * CPSC230TR					Fall 2019						HW7B
 * Stefan Carlson
 * Creates an array of 20 random 2-digit integers from 10-99.
 * Performs a bubble sort followed by a binary search of four predefined values.
 * Calculates sum and average.
 * Prints out all of these data.
 ***********************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Performs a bubble sort of the given int array
 */
void sort(int array[], int length);

/**
 * Performs a binary search given an array (assumed to be sorted), a value, and left/right bounds
 * Returns the index of the element if it exists, -1 if not
 */
int search(int array[], int x, unsigned l, unsigned r);

const int MAX = 20;

int main()
{	// Variables
	int original[MAX];
	int sorted[MAX];
	int searchItems[4] = {7, 25, 42, 91};

	unsigned sum = 0;
	double avg = 0.0;

	srand((unsigned) time(0));		// Set random seed
	for (int i = 0; i < MAX; ++i)		// For each element
	{
		original[i] = (rand() % 91) + 10; // Assign to a random int (10-99)
		sorted[i] = original[i];		// Copy to sorted array
		sum += original[i];		// Add to sum
	}

	sort(sorted, MAX);		// Perform bubble sort

	int index;
	for (int n : searchItems)		// For each item we want to search for
	{
		index = search(sorted, n, 0, MAX - 1);		// Search for the item and store the index
		if (index < 0)		// Item is not found
		{
			cout << "The number " << n << " was not found.\n";
		} else		// Item is found
		{
			cout << "The number " << n << " was found at index " << index << ".\n";
		}
	}

	avg = sum / MAX;		// Calculate average

	// Output
	cout << "\nOriginal Array:\n";		// Print original array using enhanced for loop
	for (int n : original)
	{
		cout << n << endl;
	}

	cout << "\nSorted Array:\n";		// Print sorted array using enhanced for loop
	for (int n : sorted)
	{
		cout << n << endl;
	}

	cout << "\nSum: " << sum << "\nAverage: " << avg << endl;
}

void sort(int array[], int length)
{
	int x, y;	// We'll move down on the y axis (passes), sorting through the array each time
	bool swapped = true;		// If no swaps are made during a pass, we'll stop sorting
	for (y = 0; y < length - 1 && swapped; ++y)		// Continue with new passes until the whole array is sorted
	{
		swapped = false;		// Reset swap test
		for (x = 0; x < length - y - 1; ++x)	// We'll skip the last 'y' elements since they're already sorted
		{
			if (array[x] > array[x + 1])		// If the element is greater than the one immediately to the right
			{
				int temp = array[x];		// Swap the elements
				array[x] = array[x + 1];
				array[x + 1] = temp;
				swapped = true;		// The sort isn't done, so keep going
			}
		}
	}
}

int search(int array[], int x, unsigned l, unsigned r)
{
	if (r >= l && r <= MAX - 1)	// Validate call
	{
		int mid = (l + r) / 2;		// Find middle element between left and right bounds

		if (array[mid] == x)		// If the middle element is the one we're looking for
		{
			return mid;
		} else if (x < array[mid])	// Element is left of the middle
		{
			return  (search(array, x, l, mid - 1));	// Right bound is one left of mid; search again
		} else	// x > array[mid]	// Element is right of the middle
		{
			return  (search(array, x, mid + 1, r));	// Right bound is one right of mid; search again
		}
	}

	// If we hit here, the element isn't in the array or the call is invalid
	return -1;
}
