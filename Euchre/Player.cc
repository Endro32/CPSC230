/*
 * Player.cc
 *
 *  Created on: Oct 15, 2019
 *      Author: webk7
 */
#include <iostream>
#include <string>

#include "Player.h"

Player::Player(std::string n)
{
	name = n;
	std::cout << "Hello, my name is " << name << std::endl;

}

Player::~Player()
{
	std::cout << "Player deleted\n";
}
