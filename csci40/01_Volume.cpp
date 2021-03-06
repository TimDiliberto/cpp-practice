/*
 * Program: Volume.cpp
 * Written by: Timothy Diliberto
 * Reads a radius from the user, prints the volume and surface area of a sphere
 * Last modified 3/6/2021
 */

#include <iostream>

int main() {
	const double PI = 3.14159;
	double radius,
	       volume,
	       surfaceArea;

	std::cout << "Enter radius of sphere: ";
	std::cin >> radius;

	volume = 4.0 / 3.0 * PI * radius * radius * radius;
	surfaceArea = 4.0 * PI * radius * radius;

	std::cout << "Volume: " << volume
	          << "\nSurface Area: " << surfaceArea << '\n';

	return 0;
}
