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

Player::Player(): human(true) {
	std::cout << "Please enter a username: ";
	std::cin >> name;
}

Player::Player(std::string n): name(n), human(false) {
	std::cout << "Hello, my name is " << name << std::endl;
}

Player::~Player() { }

// Until the AI is done, all decisions will be made by the user
bool Player::promptPickUp() {
	std::string s;
	std::cout << "Do you want the dealer to pick it up? [Y/n]: ";
	std::cin >> s;
	return std::tolower(s[0]) == 'y';
}
bool Player::decidePickUp() {
	return promptPickUp();
}

bool Player::promptGoAlone() {
	std::string s;
	std::cout << "Do you want to go alone? [Y/n]: ";
	std::cin >> s;
	return std::tolower(s[0]) == 'y';
}
bool Player::decideGoAlone() {
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
	} while (i > hand.size() || i <= 0);

	return i - 1;
}
int Player::decidePlayCard() {
	return promptPlayCard();
}

// Clears the player's hand
void Player::clearHand() {
	hand.clear();
}

/** Pass a pointer to the player. If the hand isn't full, the pointer will be added to the hand vector
 *  If it fails, it will return false
 */
bool Player::giveCard(Card *c) {
	if(hand.size() >= 5)
		return false;

	hand.push_back(c);
	return true;
}

// Get the number cards in the player's hand
std::vector<Card*>::size_type Player::getHandSize() {
	return hand.size();
}

Card *Player::getLastPlayedCard() {
	return lastPlayed;
}

// Request that the player decide to have the dealer pick it up or not
bool Player::wantPickUp() {
	if (human)
		return promptPickUp();
	else
		return decidePickUp();
}

// Ask if the player wants to go alone
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
Card *Player::playCard() {
	int i;
	if (hand.size() == 1)
		i = 0;
	else if (human)
		i = promptPlayCard();
	else
		i = decidePlayCard();

	lastPlayed = hand[i];
	hand.erase(hand.begin() + i);

	return lastPlayed;
}

void Player::winTrick() {
	tricksWon++;
}
