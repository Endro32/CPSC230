/*
 * Player.cc
 *
 *  Created on: Oct 15, 2019
 *      Author: webk7
 */
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

Player::Player(std::string n, bool h) {
	name = n;
	human = h;
	std::cout << "Hello, my name is " << name << std::endl;

}

Player::~Player() {
	std::cout << "Player deleted\n";
}

// Until the AI is done, all decisions will be made by the user
bool promptPickUp() {
	std::string s;
	std::cout << "Do you want the dealer to pick it up? [Y/n]: ";
	std::cin >> s;
	return std::tolower(s[0]) == 'y';
}
bool decidePickUp() {
	return promptPickUp();
}

bool promptGoAlone() {
	std::string s;
	std::cout << "Do you want to go alone? [Y/n]: ";
	std::cin >> s;
	return std::tolower(s[0]) == 'y';
}
bool decideGoAlone() {
	return promptGoAlone();
}

int Player::promptPlayCard() {
	std::string s;
	int i;

	do {
		if (!s.empty())
			std::cout << "That's not a valid card!\n";

		std::cout << "Which card do you want to play? [1-" << hand.size() << "]: ";
		std::cin >> s;
		i = s[0] - '0';
	} while(i > hand.size() || i <= 0);

	return i;
}
int Player::decidePlayCard() {
	return promptPlayCard();
}

void clearHand() {}
bool giveCard(Card &c) {}
std::vector<Card*>::size_type Player::getHandSize() {
	return hand.size();
}

bool Player::wantPickUp() {
	if (human)
		return promptPickUp();
	else
		return decidePickUp();
}

bool Player::goingAlone() {
	if (human)
		return promptGoAlone();
	else
		return decideGoAlone();
}

/**
 * Asks user to play a card
 * User or AI decides which card to play. That card is then removed from the hand and returned
 */
Card &Player::playCard() {
	int i;
	if (human)
		i = promptPlayCard();
	else
		i = decidePlayCard();

	Card card = hand[i];
	hand.erase(hand.begin() + i);

	return card;
}
