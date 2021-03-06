/**
 * Program: 04_LargerThanN.cpp
 * Written by: Timothy Diliberto
 * Given an array of integers and integer n, the function displays all integers
 *     in the array which are larger than n.
 * Last modified: 3/5/2021
 */

#include <iostream>

// Function prototypes
void largerThanN(int [], int, int);

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 28, 9, 18, 36, 2, 12, 24, 22, 46, 48 },
	n;

    std::cout << "Enter an integer: ";
    std::cin >> n;

    largerThanN(arr, SIZE, n);

    return 0;
}

void largerThanN(int arr[], int size, int n) {
    bool noneLarger = true;

    std::cout << "The numbers greater than n are: ";

    for (int index = 0; index < size; ++index) {
	if (arr[index] > n) {
	    std::cout << arr[index] << " ";
	    noneLarger = false;
	}
    }

    if (noneLarger) std::cout << "none.\n";
    else std::cout << '\n';
}
