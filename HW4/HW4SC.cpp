/*******************************************************************
 * CPSC 230                 Fall 2019 TR                HW #4
 * Stefan Carlson
 * Calculates the surface area of a cube and a sphere
 * given the side length and radius, respectively
 * *****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double cube_surf(double);
double sphere_surf(double);

const double PI = 3.141592;

int main()
{
    // Variables
    double side, radius;
    double s_cube, s_sphere;
    
    // Input
    cout << "Enter side of cube: ";
    cin >> side;
    cout << "Enter radius of sphere: ";
    cin >> radius;
    
    // Computation
    s_cube = cube_surf(side);
    s_sphere = sphere_surf(radius);
    
    // Output
    cout << showpoint << setprecision(2) << fixed;
    cout << "The surface of a cube of sides " << side << " is " << s_cube << endl
        << "The surface of a sphere of radius " << radius << " is " << s_sphere << endl;
    return 0;
}

/**
 * Takes the side length of a cube and returns the surface area
 */
double cube_surf(double s)
{
    double surface = 6 * s * s * 100;
    return floor(surface + 0.5) / 100;
}

/**
 * Takes the radius of a sphere and returns the surface area
 */
double sphere_surf(double r)
{
    double surface = 4 * PI * r * r * 100;
    return floor(surface + 0.5) / 100;
}
