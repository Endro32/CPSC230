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
    string rank;
    cin >> rank;
	render(rank);
}

/**
 * Clear screen and redraw everything
 */
void render(string rank)
{
    system("cls");
    
    cout << getCardLine(0, rank, suits::hearts) << endl;
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
    cout << getCardStackLine(6, 5);
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
