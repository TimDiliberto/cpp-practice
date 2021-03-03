/*
 * Program: OverUnderFlow.cpp
 * Written by: Timothy Diliberto
 * Tests what the code does when overflow or underflow occur
 * Last modified: 12/06/2020
 */

#include <iostream>

using namespace std;

int main() {
	float test;

	test = 2.0e38 * 1000;    // Should overflow test.
	cout << "Overflow test: " << test << endl;
	
	test = 2.0e-38 / 2.0e38;  // Should underflow test.
	cout << "Underflow test: " << test << endl;

	return 0;
}
