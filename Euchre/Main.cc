/*
 * Main.cc
 *
 *  Created on: Sep 17, 2019
 *      Author: webk7
 */

/*
 * The cards are represented by string keys: "rank.suitname"
 * 
 * Each player is represented by an object of the Player type (class to be implemented)
 * This class stores the data for the cards in the player's hand
 * It also has functions for working playing the cards that are in their hand
 * Finally, the player class contains all the code for the NPC AI, though these functions are not used by the human player
 */

#include <iostream>
#include <sstream>
#include <windows.h>

#include "Player.h"
#include "Deck.h"

using namespace std;

// Function prototypes
void render();
string getCardLine(int, string, string);
string getCardStackLine(int, int);
string space(int);

// Game class
/*
class Game {
	Player players[] = new Player[4];
	//Deck *deck;
	public:
		Game() {
			players[0] = new Player("Stefan");
			players[1] = new Player("Ultron");
			players[2] = new Player("Jarvis");
			players[3] = new Player("Friday");

			//deck = new Deck();
		}
		~Game() {
			delete players[0];
			delete players[1];
			delete players[2];
			delete players[3];

			delete players;
			//delete deck;
		}
};*/

int main() {
    SetConsoleOutputCP(65001);
    
    Deck deck;
    deck.shuffle();
    Card a = deck.dealCard();
    cout << a.getRankAsString() << " of " << a.getSuitAsString() << endl;
    Card b = deck.dealCard();
    cout << b.getRankAsString() << " of " << b.getSuitAsString() << endl;


    // Game game;

	// render();
    return 0;
}

/**
 * Clear screen and redraw everything
 */
void render() {
    // Board size: 80x32 (might make it 80x30 at some point)
    
    system("cls");
    
    cout << space(37) << "Jarvis\n"
         << space(10) << "Hands won:" << space(12) << getCardStackLine(0, 5)
         << space(9) << "Tricks won:\n" << space(10) << "You: 5" << space(16)
         << getCardStackLine(1,5) << space(9) << "Stefan: 2\n"
         << space(10) << "Opponent: 3" << space(11) << getCardStackLine(2, 5);
}

/**
 * Returns a single line of a card, without a new line character at the end
 * int line: Line, from 0 to 6
 * string rank: Rank of the card, from 9 to A
 * string suit: Suit of the card using symbol
 */
string getCardLine(int line, string card) {
    istringstream stream(card);
    string rank, suit;
    getline(stream, rank, '.');
    getline(stream, suit, '.');
    
    string ret = "";
    if (line == 0) {
        ret = "┌───────┐";
    }
    else if (line == 2 || line == 4 ) {
        ret = "|       |";
    }
    else if (line == 6) {
        ret = "└───────┘";
    }
    else if (line == 1) {
        if (!rank.compare("10")) {
            ret = "| 10    |";
        }
        else {
            ret = "| " + rank + "     |";
        }
    }
    else if (line == 3) {
        ret = "|   " + suit + "   |";
    }
    else if (line == 5) {
        if (!rank.compare("10")) {
            ret = "|    10 |";
        }
        else {
            ret = "|     " + rank + " |";
        }
    }
    
    return ret;
}

/**
 * Returns a line of a flipped over card stack with the specified number of cards
 * int line: Line, from 0 to 6
 * int numberOfCards: Number of cards in the stack
 */
string getCardStackLine(int line, int numberOfCards) {
    string ret = "";
    string concat = " |";
    ret = getCardLine(line, " . ");
    if (line == 0)
        concat = "─┐";
    else if (line == 6)
        concat = "─┘";
    for (int i = numberOfCards; --i; i > 0)
        ret += concat;
    return ret;
}

/**
 * Returns a string with the specified number of space characters
 */
string space(int spaces)
{
    string ret(spaces, ' ');
    return ret;
}

