/*
 * Strings.h
 *
 *  Created on: Sep 17, 2019
 *      Author: webk7
 */

#ifndef STRINGS_H_
#define STRINGS_H_

#include <string>
using std::string;

string getCard(string value, string suit) {
	return  " _____\n"
		"|" + suit + "    " + value + "|";
}

namespace strings {

	// Cards from 9-A
	string card9 = getCard("9", "\u2764");
	string card10;
	string cardJack;
	string cardQueen;
	string cardKing;
	string cardAce;

}

#endif /* STRINGS_H_ */
