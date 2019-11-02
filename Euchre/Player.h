/*
 * Player.h
 *
 *  Created on: Oct 15, 2019
 *      Author: webk7
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "Deck.h"

class Player {
	private:
		std::string name;			// Player's name
		const bool human;			// True if the player is human; false if AI
		std::vector<Card*> hand;	// Stores card references for the player's hand
		Card* lastPlayed;			// Stores last played card
		int tricksWon;

		bool promptPickUp();		// User decides to make the dealer pick it up or not
		bool decidePickUp();		// AI decides to make the dealer pick  it up or not

		int promptNameTrump();		// User decides to name trump or pass
		int decideNameTrump();		// AI decides to name trump

		bool promptGoAlone();		// User decides to go alone or not
		bool decideGoAlone();		// AI decides to go alone or not

		int promptPlayCard();		// User decides which card to play
		int decidePlayCard();		// AI decides which card to play

		int promptDiscard();		// User decides which card to discard
		int decideDiscard();		// AI decides which card to discard

		void printHand();
	public:
		Player();					// Creates a human player and asks them to enter a username
		Player(std::string name);	// Creates an AI player
		virtual ~Player();

		std::string getName();

		void clearHand();			// Empties the player's hand
		void resetTricksWon();		// Sets tricks won to 0
		bool giveCard(Card*);		// Gives the player a card. Returns false if hand is full
		std::vector<Card*>::size_type getHandSize();			// Gets the number of cards in the player's hand
		Card *getLastPlayedCard();	// Gets the last played card pointer

		bool wantPickUp();			// Ask if player wants dealer to pick it up
		int nameTrump();			// Ask user to name trump or pass (return of -1)
		bool goingAlone();			// Ask if player wants to go alone
		Card *playCard();			// Ask user to play a card and returns a pointer to that card
		Card *discard();			// Ask user to discard one of their cards
		void winTrick();			// Increments tricksWon
};

#endif /* PLAYER_H_ */
