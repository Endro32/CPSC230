#include <iostream>

using namespace std;

bool compute_coins(int, int&, int&);

int main()
{
    // Variables
    int q = 0, d = 0, p = 0;
    const int QVAL = 25, DVAL = 10, PVAL = 1;
    int changeOwed = 1, remainder = 0;
    
    while (changeOwed > 0)
    {
        // Input
        cout << "How much change do you owe? (0 to quit): ";
        cin >> changeOwed;

        // Verify user input
        if (changeOwed >= 100) // If over 100, make the user do it again
        {
            cout << "BROO YOU LOOK LIKE PIZZA BRO\n";
            continue;
        } else if (changeOwed <= 0) // If less than or equal to zero, continue and exit
        {
        	continue;
        }
        
        // Computation
        remainder = changeOwed;
        if (!compute_coins(QVAL, q, remainder) ||
            !compute_coins(DVAL, d, remainder))
            return 1; // Exit with error if parameters are somehow invalid
        p = remainder;
        
        // Output
        cout << "You'll need " << q << " quarters, " << d << " dimes, and " << p << " pennies.\n\n";
    }
    
    return 0;
}

/**
 * Computes the maximum number of a certain coin attainable for a certain change value
 * Returns false if parameters are invalid
 */
bool compute_coins(int coin_value, int &num, int &amount_left)
{
    // Precondition: 0 < coin_value < 100; 0 <= amount_left < 100
    if (coin_value <= 0 || coin_value >= 100 || amount_left  < 0 || amount_left >= 100)
        return false;
    
    num = amount_left / coin_value;
    amount_left = num % coin_value;
    return true;
}
