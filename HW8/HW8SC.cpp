/******************************************************************************
 * CPSC230-TR				Fall 2019				HW 8
 * Stefan Carlson
 * A virtual phone book program to manage contacts
 *****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Prototypes
void showPhoneBook(vector<string> &N, vector<int> &P);
int toChoice(char c);
void editNum(vector<string> &N, vector<int> &P, int c1);
void addNum(vector<string> &N, vector<int> &P);

const int MAX = 10;

int main()
{
	//variables
	string eleName;
	int elePhone;
	char choice;
	vector<string> name(10, "");
	name[0] = "Andrico";
	name[1] = "Bonnie";
	name[2] = "Charles";
	name[3] = "Debbie";
	name[4] = "Enrique";
	name[5] = "Felicia";

	vector<int> phone(10, 0);
	phone[0] = 5551234;
	phone[1] = 5555678;
	phone[2] = 5552468;
	phone[3] = 5551379;
	phone[4] = 5559876;
	phone[5] = 5554321;

	

	do
	{
		//call function showPhoneBook
		showPhoneBook(name, phone);

		//get user request
		cout << "\n\nWho\'s phone number do you want to see?" << endl;
		cout << "remember, type \'e\' for edit, \'n\' for new, and \'x\' for exit, otherwise just type the number of the person." << endl;
		cin >> choice;

		//call function toChoice
		elePhone = toChoice(choice);

		if (choice == 'n')
		{
			addNum(name, phone);
			continue;
		}

		if (elePhone != -1)
		{
			cout << "The phone number for " << name[elePhone] << " is " << phone[elePhone] << ".\n\n\n\n\n\n";
		}
		if (choice == 'e')
		{
			int choice1;
			cout << "Which entry do you want to edit?  ";
			cin >> choice1;
			editNum(name, phone, choice1);
		}
	} while (choice != 'x');

	return 0;
}

//print function
void showPhoneBook(vector<string> &N, vector<int> &P)
{
	for (unsigned i = 0; i < N.size(); ++i)
	{
		cout << i << "  " << N[i] << "\t" << P[i] << endl;
	}
	return;
}

int toChoice(char c)
{
	int num=0;
	if (c != 'e' && c != 'x')
	{
		switch (c)
		{
		case '0':
			num = 0;
			return num;
		case '1':
			num = 1;
			return num;
		case '2':
			num = 2;
			return num;
		case '3':
			num = 3;
			return num;
		case '4':
			num = 4;
			return num;
		case '5':
			num = 5;
			return num;
		case '6':
			num = 6;
			return num;
		case '7':
			num = 7;
			return num;
		case '8':
			num = 8;
			return num;
		case '9':
			num = 9;
			return num;

		}
	
	}
	else
		return -1;
	return num;
}

void editNum(vector<string> &N, vector<int> &P, int c1)
{
	string name;
	int number;
	cout << "What is the name for entry " << c1 << "?:  ";
	cin >> name;
	cout << "What is the number for entry " << c1 << "?:  ";
	cin >> number;

	N[c1] = name;
	P[c1] = number;
	return;
}

void addNum(vector<string> &N, vector<int> &P)
{
	string name;
	int number;
	cout << "What is the name for entry " << N.size() << "?:  ";
	cin >> name;
	cout << "What is the number for entry " << P.size() << "?:  ";
	cin >> number;

	N.push_back(name);
	P.push_back(number);
	return;
}
