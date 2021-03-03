/*
 * Program: RNG.cpp
 * Written by: Timothy Diliberto
 * Generates a random number between MIN and MAX
 * Last modified 12/06/2020
 */

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
	unsigned seed = time(0);
	int min, max, randNum;

	srand(seed);

	cout << "MIN: ";
	cin >> min;
	cout << "MAX: ";
	cin >> max;

	randNum = (rand() % (max - min + 1)) + min;

	cout << "\nResult: " << randNum << endl;

	return 0;
}
