/*
 * Game.h
 *
 *  Created on: Nov 1, 2019
 *      Author: webk7
 *
 *  This class does not keep track of the cards that the players have placed on the table.
 *  Each player holds that data internally
 */

#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "Deck.h"
#include "Player.h"

class Game {
public:
	Game();
	virtual ~Game();
private:
	Deck *deck;
	std::vector<Card*> used;			// Will hold all of the cards from previous tricks
	int dealer;

	Player *player0;
	Player *player1;
	Player *player2;
	Player *player3;

	int player02Score;
	int player13Score;

	Player* getPlayer(int);				// Because I'm really lazy; gets player by index
};

#endif /* GAME_H_ */
