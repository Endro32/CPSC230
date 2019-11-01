/*
 * Player.h
 *
 *  Created on: Oct 15, 2019
 *      Author: webk7
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "Deck.h"

class Player {
	private:
		bool human;					// True if the player is human; false if AI
		std::string name;			// Player's name
		std::vector<Card*> hand;	// Stores card references for the player's hand

		bool promptPickUp();		// User decides to make the dealer pick it up or not
		bool decidePickUp();		// AI decides to make the dealer pick  it up or not

		bool promptGoAlone();		// User decides to go alone or not
		bool decideGoAlone();		// AI decides to go alone or not

		int promptPlayCard();		// User decides which card to play
		int decidePlayCard();		// AI decides which card to play
	public:
		Player(std::string name, bool human);
		virtual ~Player();

		void clearHand();			// Empties the player's hand
		bool giveCard(Card*);		// Gives the player a card. Returns false if hand is full
		std::vector<Card*>::size_type getHandSize();			// Gets the number of cards in the player's hand

		bool wantPickUp();			// Ask if player wants dealer to pick it up
		bool goingAlone();			// Ask if player wants to go alone
		Card *playCard();			// Ask user to play a card
};

#endif /* PLAYER_H_ */
