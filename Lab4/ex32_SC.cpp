#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double base = 0, exp = 1, ans = 0;
    string in = "";
    bool cont = true;
    
    // Start loop
    do
    {
        // Get base and exponent from user
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter exponent: ";
        cin >> exp;
        
        // Calculate the result
        ans = pow(base, exp);
        
        // If the base and exponent are both integers, we know the result is an integer
        // In that case, we'll deal with pow() errors, e.g. 5^2 = 24.99999999
        if (fmod(base, 1.0) == 0 && fmod(exp, 1.0) == 0)
            ans = floor(ans + 0.5);
        
        // Output
        cout << base << " to the power of " << exp << " is: " << ans << endl;
        
        // Ask user if they want to run again
        cout << "Run again? [Y/n]: ";
        cin >> in;
        if (tolower(in[0]) != 'y')
            cont = false;
        
    } while (cont);
    
    return 0;
    
}
