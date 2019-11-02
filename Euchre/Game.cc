/*
 * Game.cc
 *
 *  Created on: Nov 1, 2019
 *      Author: webk7
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"

Game::Game() {
	srand((unsigned) time(0)); 					// Set the random seed

	deck = new Deck();
	dealer = rand() % 4;

	player0 = new Player();
	player1 = new Player("Jarvis");
	player2 = new Player("Ultron");
	player3 = new Player("Friday");

	player02Score = 0;
	player13Score = 0;

	playHand();
}

Game::~Game() {
	delete deck;

	delete player0;
	delete player1;
	delete player2;
	delete player3;
}

// Gets player by index (0 is human, then clockwise)
Player *Game::getPlayer(int i) {
	if (i >= 4)
		i = i % 4;

	if (i <= 0)
		return player0;
	else if (i == 1)
		return player1;
	else if (i == 2)
		return player2;
	else
		return player3;
}

// Resets and shuffles deck, deals each player five cards after clearing their hand
void Game::dealHand() {
	//deck->shuffle();
	Player *cur;
	for (int p = 0; p < 4; p++) {		// For each player
		cur = getPlayer(p);
		cur->clearHand();
		for (int c = 0; c < 5; c++) {	// For five cards
			cur->giveCard(deck->dealCard());
		}
	}

	std::cout << "Cards have been dealt!\n";
}

void Game::playTrick() {

}

void Game::playHand() {
	if (++dealer > 4) // Increment dealer and loop back to zero if necessary
		dealer = 0;
	Player *dealerO = getPlayer(dealer);		// Dealer Object
	std::cout << dealerO->getName() << " is dealer.\n";

	dealHand();
	top = deck->flipTop();
	std::cout << "Top card is " << top->getSuitAsString() << std::endl;

	Player *player;
	for (int i = 1; i < 10; i++) {		// Should never terminate here, but just in case, it won't be an infinite loop
		player = getPlayer((i + dealer) % 4);

		if (i <= 4) {
			if (player->wantPickUp()) {	// If player wants dealer to pick it up
				trump = top->getSuit();
				std::cout << player->getName() << " made the dealer pick it up.\n";
				deck->put_back(dealerO->discard());
				dealerO->giveCard(deck->dealCard());
				break;

			} else {	// Player passed
				std::cout << player->getName() << " passed.\n";
				continue;
			}

		} else if (i <= 8) {
			// nameTrump() has built-in validation, so none is needed here
			int t = player->nameTrump();
			if (t != -1) {	// If player named trump
				trump = t;
				std::cout << player->getName() << " named trump.\n";
				break;

			} else {	// Player passed
				std::cout << player->getName() << " passed.\n";
				continue;
			}

		} else {
			std::cout << "\nReturning...\n";
			return;
		}
	}

	std::cout << "Trump is " << trump;

}
