#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int a = 1, b = 0, c = 1; // Coefficients
    double rad, x1, x2; // Radical expression and two roots
    
    // Get the input
    cout << "Enter a quadratic function\na: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    
    // If leading coefficient is 0
    if (a == 0)
    {
        cout << "That isn't even a quadratic, yo.";
        return 1;
    }
    
    // Calculate value inside radical
    rad = pow(b, 2) - 4 * a * c;
    // If it's zero, the roots are imaginary
    if (rad < 0)
    {
        cout << "Imaginary number!";
        return 1;
    }
    
    // Finish calculating the roots
    rad = sqrt(rad);
    x1 = (-b + rad) / 2 * a;
    x2 = (-b - rad) / 2 * a;
    
    // Output
    cout << "The roots are x=" << x1 << " and x=" << x2;
    
    return 0;
    
}
