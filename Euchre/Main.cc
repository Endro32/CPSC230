/*
 * Main.cc
 *
 *  Created on: Sep 17, 2019
 *      Author: webk7
 */

#include <iostream>
#include <windows.h>

//#include "Strings.h"

using namespace std;

// Function prototypes
void render(string);
string getCardLine(int, string, string);
string getCardStackLine(int, int);
string space(int);

namespace suits
{
    const string hearts = "♥";
    const string spades = "♠";
    const string diamonds = "♦";
    const string clubs = "♣";
}

int main()
{
    SetConsoleOutputCP(65001);
    
	render("A");
}

/**
 * Clear screen and redraw everything
 */
void render(string rank)
{
    // Board size: 80x32 (might make it 80x30 at some point)
    
    system("cls");
    
    cout << space(37) << "Jarvis\n"
         << space(10) << "Hands won:" << space(12) << getCardStackLine(0, 5)
         << space(9) << "Tricks won:\n" << space(10) << "You: 5" << space(16)
         << getCardStackLine(1,5) << space(9) << "Stefan: 2\n"
         << space(10) << "Opponent: 3" << space(11) << getCardStackLine(2, 5);
    
    
   /* cout << getCardLine(0, rank, suits::hearts) << endl;
    cout << getCardLine(1, rank, suits::hearts) << endl;
    cout << getCardLine(2, rank, suits::hearts) << endl;
    cout << getCardLine(3, rank, suits::hearts) << endl;
    cout << getCardLine(4, rank, suits::hearts) << endl;
    cout << getCardLine(5, rank, suits::hearts) << endl;
    cout << getCardLine(6, rank, suits::hearts) << endl << endl;
    
    cout << getCardStackLine(0, 5) << endl;
    cout << getCardStackLine(1, 5) << endl;
    cout << getCardStackLine(2, 5) << endl;
    cout << getCardStackLine(3, 5) << endl;
    cout << getCardStackLine(4, 5) << endl;
    cout << getCardStackLine(5, 5) << endl;
    cout << getCardStackLine(6, 5);*/
}

/**
 * Returns a single line of a card, without a new line character at the end
 * int line: Line, from 0 to 6
 * string rank: Rank of the card, from 9 to A
 * string suit: Suit of the card using symbol
 */
string getCardLine(int line, string rank, string suit)
{
    string ret = "";
    if(line == 0)
    {
        ret = "┌───────┐";
    }
    else if(line == 2 || line == 4 )
    {
        ret = "|       |";
    }
    else if(line == 6)
    {
        ret = "└───────┘";
    }
    else if(line == 1)
    {
        if(!rank.compare("10"))
        {
            ret = "| 10    |";
        }
        else
        {
            ret = "| " + rank + "     |";
        }
    }
    else if(line == 3)
    {
        ret = "|   " + suit + "   |";
    }
    else if(line == 5)
    {
        if(!rank.compare("10"))
        {
            ret = "|    10 |";
        }
        else
        {
            ret = "|     " + rank + " |";
        }
    }
    
    return ret;
}

/**
 * Returns a line of a flipped over card stack
 * int line: Line, from 0 to 6
 * int numberOfCards: Number of cards in the stack
 */
string getCardStackLine(int line, int numberOfCards)
{
    string ret = "";
    string concat = " |";
    ret = getCardLine(line, " ", " ");
    if(line == 0)
        concat = "─┐";
    else if(line == 6)
        concat = "─┘";
    for(int i = numberOfCards; --i; i > 0)
        ret += concat;
    return ret;
}

string space(int spaces)
{
    string ret(spaces, ' ');
    return ret;
}
