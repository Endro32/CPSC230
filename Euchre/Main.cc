/*
 * Main.cc
 *
 *  Created on: Sep 17, 2019
 *      Author: webk7
 */

#include <iostream>

//#include "Strings.h"

using namespace std;

string getCard(string, string);

const string hearts = "♥";
const string spades = "♠";
const string diamonds = "♦";
const string clubs = "♣";

int main() {
	system("cls");
	cout << getCard("9", hearts);
}

string getCard(string value, string suit) {
	return  "┌───────┐\n"
		"| " + value + "     |\n"
		"|       |\n"
		"|   " + suit + "   |\n"
		"|       |\n"
		"|     " + value + " |\n"
		"└───────┘";
}
