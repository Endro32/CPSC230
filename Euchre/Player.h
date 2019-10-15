/*
 * Player.h
 *
 *  Created on: Oct 15, 2019
 *      Author: webk7
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
	public:
		Player(std::string n);
		virtual ~Player();
	private:
			std::string name;
};

#endif /* PLAYER_H_ */
