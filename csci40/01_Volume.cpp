/*
 * Program: Volume.cpp
 * Written by: Timothy Diliberto
 * Reads a radius from the user, prints the volume and surface area of a sphere
 * Last modified 12/06/2020
 */

#include <iostream>

using namespace std;

int main() {
	const double PI = 3.14159;
	double radius,
	       volume,
	       surfaceArea;

	cout << "Enter radius of sphere: ";
	cin >> radius;

	volume = 4.0 / 3.0 * PI * radius * radius * radius;
	surfaceArea = 4.0 * PI * radius * radius;

	cout << "Volume: " << volume << endl
	     << "Surface Area: " << surfaceArea << endl;

	return 0;
}
