/**
 * Program: 01_LargestSmallest.cpp
 * Written by: Timothy Diliberto
 * Prompts user to enter 10 integers into an array. Displays largest and
 *     smallest integers from the array
 * Last modified: 3/4/2021
 */

#include <iostream>

int main() {
    const int SIZE = 10;
    int largest,
	smallest,
	arr[SIZE];

    for (int &num : arr) {
	std::cout << "Enter an integer: ";
	std::cin >> num;
    }

    largest = smallest = arr[0];

    for (int num : arr) {
	if (num > largest) largest = num;
	else if (num < smallest) smallest = num;
    }

    std::cout << "Largest element: " << largest << std::endl
	      << "Smallest element: " << smallest << std::endl;

    return 0;
}
