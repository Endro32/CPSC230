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

Player::Player(): human(true), tricksWon(0) {
	std::cout << "Please enter a username: ";
	std::cin >> name;
}

Player::Player(std::string n): name(n), human(false), tricksWon(0) {
	std::cout << "Hello, my name is " << name << std::endl;
}

Player::~Player() { }

// Until the AI is done, all decisions will be made by the user
bool Player::promptPickUp() {
	printHand();

	std::string s;
	std::cout << "Do you want the dealer to pick it up? [Y/n]: ";
	std::cin >> s;
	return std::tolower(s[0]) == 'y';
}
bool Player::decidePickUp() {
	return promptPickUp();
}

int Player::promptNameTrump() {
	int t = 5;
	std::string in;

	while (t > 4 || t < -1) {
		if (!in.empty())
			std::cout << "Invalid choice!\n";

		std::cout << "Would you like to name trump? [Spades, Hearts, Clubs, Diamonds, Pass]: ";
		std::cin >> in;

		switch (std::tolower(in[0])) {
		case 's':
			return Card::SPADES;
		case 'h':
			return Card::HEARTS;
		case 'c':
			return Card::CLUBS;
		case 'd':
			return Card::DIAMONDS;
		case 'p':
			return -1;
		}
	} ;

	return t; // Should never hit this point, but just in case
}
int Player::decideNameTrump() {
	return promptNameTrump();
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
	printHand();

	std::string s;
	int i;

	do {
		if (!s.empty())
			std::cout << "That's not a valid card!\n";

		std::cout << "Which card do you want to play? [1-" << hand.size() << "]: ";
		std::cin >> s;
		i = s[0] - '0';
	} while (i > static_cast<int>(hand.size()) || i <= 0);

	return i - 1;
}
int Player::decidePlayCard() {
	return promptPlayCard();
}

int Player::promptDiscard() {
	printHand();

		std::string s;
		int i;

		do {
			if (!s.empty())
				std::cout << "That's not a valid card!\n";

			std::cout << "Which card would you like to discard? [1-" << hand.size() << "]: ";
			std::cin >> s;
			i = s[0] - '0';
		} while (i > static_cast<int>(hand.size()) || i <= 0);

		return i - 1;
}
int Player::decideDiscard() {
	return promptDiscard();
}

void Player::printHand() {
	std::cout << name << ", your cards are:\n";
	Card *c;
	for (unsigned i = 0; i < hand.size(); i++) {
		c = hand[i];
		std::cout << i + 1 << ". " << c->getRankAsString() << " of " << c->getSuitAsString() << std::endl;
	}
}

std::string Player::getName() {
	return name;
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

int Player::nameTrump() {
	if (human)
			return promptNameTrump();
		else
			return decideNameTrump();
}

// Ask if the player wants to go alone
bool Player::goingAlone() {
	if (human)
		return promptGoAlone();
	else
		return decideGoAlone();
}

/**
 * Asks player to play a card
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

/**
 * Asks player to discard a card
 * User or AI decides which card to discard. That card is then removed from the hand and returned
 */
Card *Player::discard() {
	int i;
	if (hand.size() == 1)
		i = 0;
	else if (human)
		i = promptDiscard();
	else
		i = decideDiscard();

	Card* ret;
	hand.erase(hand.begin() + i);

	return ret;
}

void Player::winTrick() {
	tricksWon++;
}
