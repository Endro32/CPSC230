/* Exercise 3.4
 * 
 * A.
 *   ceil of 34.6 is 35
 *   floor of 34.6 is 34
 * B.
 *   floor of -33.2 is -34
 *   ceil of -33.2 is -33
 * C.
 *   34.2 rounds to 34
 *   34.6 rounds to 35
 *   -33.2 rounds to -33
 *   -33.7 rounds to -34
 * D.
 *   Add 0.5 and pass to floor function
 *   Implemented below
 * 
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Initialize values
    double values[] = {34.2, 34.6, -33.2, -33.7};
    
    // Apply rounding logic from part D. to each value
    for (double d : values)
    {
        double rounded = floor(d + 0.5);
        cout << d << " rounds to " << rounded << endl;
    }
    
    return 0;
}
