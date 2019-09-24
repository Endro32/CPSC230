/**************************************************************************************
 *              CPSC 230 TR             2019                Homework #3
 * Stefan Carlson
 *      This is a Final Fantasy style game. It is inspired by, well, Final Fantasy
 *      and includes lore from the TV show Avatar: The Last Airbender. You'll fight
 *      through five monsters, getting more difficult each time. If you die, the game
 *      ends. If you beat all five, you win the game. As you defeat monsters, you gain
 *      their points. As you gain more points, you will face more difficult monsters.
 **************************************************************************************/

/* Game design:
 * 
 * There are four attacks:
 * 0 Cosmetics (1 point)
 * 1 Tools (1000 points)
 * 2 Blitz (2000 points)
 * 3 Fire (600 points)
 * 
 * There are four monsters:
 * 0 Badger Mole (400 points)
 * 1 Armadillo Bear (600 points)
 * 2 Shirshu (800 points)
 * 3 Dragon (1000 points)
 * 
 * Attacks have damage multipliers and a custom message for each monster
 */

/* Algorithm
 * 1. Create message and points tables and populate with data
 * 2. Declare the following variables:
 *  A. string to hold the player's username, initialize to ""
 *  B. int to hold the player's current points, initialize to 100
 *  C. int to hold random range for choosing monster, initialize to 2
 *  D. int to hold offset, will be added to monster value, initialize to 0
 *  E. int to hold damage multiplier, initialize to 1
 *  F. 2 ints to hold attack choice and monster, respectively
 * 3. Ask player to enter username, store to username variable
 * 4. Introduce game, tell user how many points they start with
 * 5. Loop to be iterated five times:
 *  1. Randomly choose a monster based on user's current points:
 *   A. If user has over 1000 points, set range to 3 and offset to 1
 *   B. Else if user has over 500 points, set range to 3 and offset to 0
 *   C. Else set range to 2 and offset to 0
 *   D. Generate random number between 0 and range. Assign to monster variable
 *  2. Tell user which monster they have encountered
 *  3. Display list of attack choices
 *  4. Get choice from user, store to attack variable
 *  5. Look up message in messages table and print to screen
 *  6. Look up point net in points table and add to user's points
 *  7. If points is less than zero, the user has lost
 *   A. Tell the user they lost
 *   B. Exit the program with code 0
 *  8. Otherwise, tell the user they won the battle
 *  9. Tell the user their current points
 * 6. Tell the user they won the tournament
 * 7. Exit the program with code 0
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // So first we're gonna create our two tables: message and points, both attack vs monster
    string messages[4][4];
    int netpoints[4][4];
    // Adding messages to the message table
    messages[0][0] = "spilled perfume on the floor, dealing 1 damage.\nBadger mole crushed you with earthbending, dealing 3000 damage.";
    messages[0][1] = "spilled perfume on the floor, dealing 1 damage.\nArmadillo bear mauled you with his teeth, dealing 2000 damage.";
    messages[0][2] = "spilled perfume on the floor, blinding the shirshu and dealing 1000 damage."; //(1000x)
    messages[0][3] = "spilled perfume on the floor, dealing 1 damage.\nDragon incinerated you with firebending, dealing 5000 damage.";
    
    messages[1][0] = "attacked badger mole with a chainsaw, dealing 1000 damage.";
    messages[1][1] = "attacked armadillo bear with a chainsaw, dealing 100 damage.\nArmadillo bear mauled you with his teeth, dealing 2000 damage."; //(0.1x)
    messages[1][2] = "attacked shirshu with a chainsaw, dealing 1000 damage.";
    messages[1][3] = "attacked dragon with a chainsaw, dealing 1000 damage.";
    
    messages[2][0] = "suplexed badger mole, dealing 2000 damage.";
    messages[2][1] = "suplexed armadillo bear, dealing 2000 damage.";
    messages[2][2] = "suplexed shirshu, dealing 500 damage.\nShirshu attacked you with toxins and claws, dealing 4000 damage."; //(0.25x)
    messages[2][3] = "suplexed dragon, dealing no damage.\nDragon incinerated you with firebending, dealing 5000 damage."; //(0x)
    
    messages[3][0] = "attacked badger mole with fire, dealing 600 damage.";
    messages[3][1] = "attacked armadillo bear with fire, dealing 600 damage.";
    messages[3][2] = "attacked shirshu with fire, dealing 600 damage.\nShirshu attacked you with toxins and claws, dealing 4000 damage.";
    messages[3][3] = "attacked dragon with fire, dealing no damage.\nDragon incinerated you with firebending, dealing 5000 damage."; //(0x)
    
    // Adding points to the netpoints table (refer to messages table to see which entry is which)
    netpoints[0][0] = -3000;
    netpoints[0][1] = -2000;
    netpoints[0][2] = 800;
    netpoints[0][3] = -5000;
    
    netpoints[1][0] = 400;
    netpoints[1][1] = -2000;
    netpoints[1][2] = 800;
    netpoints[1][3] = 1000;
    
    netpoints[2][0] = 400;
    netpoints[2][1] = 600;
    netpoints[2][2] = -4000;
    netpoints[2][3] = -5000;
    
    netpoints[3][0] = 400;
    netpoints[3][1] = 600;
    netpoints[3][2] = -4000;
    netpoints[3][3] = -5000;
    
    // Now let's create the game variables
    string username = "";
    int points = 100;
    int range = 1, offset = 0;
    int multiplier = 1;
    int attack, monster;
    
    // Set random seed
    srand(time(NULL));
    
    // Request username and introduce game
    cout << "To begin, please choose a username: ";
    cin >> username;
    cout << "Welcome to the game, " << username << "!\nYou currently have " << points << " points.\n\n";
    
    // Battle loop runs five times
    for(int i = 0; i < 5; i++)
    {
        // Determine available monster choices based on user's current score
        if(points > 1000) // Available options are armadillo bear, shirshu, and dragon
        {
            range = 3;
            offset = 1;
        }
        else if(points > 500) // Available options are badger mole, armadillo bear, and shirshu
        {
            range = 3;
            offset = 0;
        }
        else // Available options are badger mole and armadillo bear
        {
            range = 2;
            offset = 0;
        }

        // Randomly choose a monster
        monster = (rand() % range) + offset;
        
        string output = "";
        switch(monster) // Set output based on which monster was chosen by the RNG
        {
        case 0:
            output += "a badger mole with 400 points";
            break;
        case 1:
            output += "an armadillo bear with 600 points";
            break;
        case 2:
            output += "a shirshu with 800 points";
            break;
        case 3:
            output += "a dragon with 1000 points";
            break;
        }
        // Tell user which monster they encountered and display list of attack choices
        cout << "In your travels you have encountered "<< output << "!\nChoose an attack:"
             << "\n1. Cosmetics\n2. Tools\n3. Blitz\n4. Fire\n";
        // Get user choice, and subtract one to convert to array index
        cin >> attack;
        attack -= 1;
        
        // Battle results
        cout << "\n\n" << username << " " << messages[attack][monster] << endl;
        points += netpoints[attack][monster];
        if(points <= 0) // If user loses, tell them game over and exit the program
        {
            cout << username << " has lost the battle. Game over!";
            return 0;
        }
        // If execution makes it here, the user has won the battle, so tell them
        cout << username << " has won the battle. Congratuations!\n";
        if(i < 5)
            cout << "You now have " << points << " points.\n\n";
    }
    
    // If execution makes it here, the user has survived all of the battles
    cout << username << " survived all of the battles and finished with a total of " << points << " points. Great job!";
    return 0;
}
