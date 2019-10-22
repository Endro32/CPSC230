/*
 * Deck.cc
 *
 *  Created on: Oct 22, 2019
 *      Author: webk7
 */

#include <iostream>

#include "Deck.h"

// Card Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 * int suit
 * int rank
 */

Card::Card(int s, int r) {
	if (suit < 0 || suit > 3 || (rank != 1 && rank < 9) || rank > 13) {
		std::cout << "An internal error has occurred";
		// TODO throw an exception
	}
	// It has now been officially determined that the rank and suit given are valid

	suit = s;
	rank = r;
}

Card::~Card() {

}

int Card::getSuit() {
	return suit;
}

/**
 * Returns the symbol for the given suit as a string
 */
static std::string Card::getSuitSymbol(int s) {
	switch (s) {
	case Card::SPADES:		return Card::SPADESYM;
	case Card::HEARTS:		return Card::HEARTSYM;
	case Card::DIAMONDS:	return Card::DIAMONDSYM;
	case Card::CLUBS:		return Card::CLUBSYM;
	default:				return "";
	}
}

/**
 * Returns the symbol for the suit of this card
 */
std::string Card::getSuitSymbol() {
	return getSuitSymbol(suit);
}

/**
 * Returns the name of this card's suit as a string
 */
std::string Card::getSuitAsString() {
	switch (suit) {
	case Card::SPADES:		return "Spades";
	case Card::HEARTS:		return "Hearts";
	case Card::DIAMONDS:	return "Diamonds";
	case Card::CLUBS:		return "Clubs";
	default:				return "";
	}
}

int Card::getRank() {
	return rank;
}

/**
 * Returns the name of this card's rank as a string
 */
std::string Card::getRankAsString() {
	switch (rank) {
	case Card::ACE:			return "Ace";
	case 9:					return "9";
	case 10:				return "10";
	case Card::JACK:		return "Jack";
	case Card::QUEEN:		return "Queen";
	case Card::KING:		return "King";
	default:				return "";
	}
}

/**
 * Returns a strength value between 0 and 13
 * 1-6 denotes the rankings of the currently played suit
 * 7-13 denotes the rankings of the trump cards
 * 0 denotes a card from a suit other than the currently played suit or trump
 */
int Card::getStrength(int trump, int curSuit) {
	if (suit == trump) { 		// Return values for cards of trump suit
		switch (rank) {
		case 9:				return 7;
		case 10:			return 8;
		case Card::QUEEN:	return 9;
		case Card::KING:	return 10;
		case Card::ACE:		return 11;
		case Card::JACK:	return 13;
		}
	}

	int leftBower;				// Determine which suite the left bower is in
	if (suit == Card::SPADES || suit == Card::HEARTS)
		leftBower = suit + 2;
	else if (suit == Card::DIAMONDS || suit == Card::CLUBS)
		leftBower = suit - 2;
								// Now check if this card is the left bower
	if (suit == leftBower && rank == Card::JACK)
		return 12;				// Return value for the left bower

	if (suit == curSuit) {		// If card is from the current suit
		if (rank == Card::ACE)	// Return value for the ace of current suit
			return 6;
		else					// Return value for all other cards of current suit
			return rank - 8;
	}
	else {						// Return value for all other cards
		return 0;
	}
}

// Deck Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Deck::Deck() {
	// TODO Auto-generated constructor stub

}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}


