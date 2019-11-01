/*
 * Game.cc
 *
 *  Created on: Nov 1, 2019
 *      Author: webk7
 */

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
