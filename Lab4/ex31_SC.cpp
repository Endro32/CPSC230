#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 2, b = 4, c = 0;
    
    c = pow(a, b) + 0.5;
    cout << a << " to the power of " << b << " is: " << c << endl;
    
    a = 3, b = 3;
    c = pow(a, b) + 0.5;
    cout << a << " to the power of " << b << " is: " << c << endl;
    
    a = 5, b = 4;
    c = pow(a, b) + 0.5;
    cout << a << " to the power of " << b << " is: " << c << endl;
    
    return 0;
    
}
