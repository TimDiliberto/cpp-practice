/*
 * Program: Commas.cpp
 * Written by: Timothy Diliberto
 * Accepts a 7-9 digit number, prints commas between every third number
 * Last modified 12/06/2020
 */

#include <iostream>

using namespace std;

int main() {
	int number,
	    temp,
	    first,
	    second,
	    third;

	cout << "Enter a 7-9 digit number: ";
	cin >> number;

	third = number & 100;
	temp = number / 100;
	second = temp % 100;
	first = temp / 100;

	cout << first << "," << second << "," << third << endl;

	return 0;
}
