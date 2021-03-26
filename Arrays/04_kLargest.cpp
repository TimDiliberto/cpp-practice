/**
 * Given an array of integers, sorts using selection sort then outputs the
 *     k largest element to the terminal
 *
 * @file 01_LargestElem.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/22/2021
 */

#include "../ArrayUtils.h"
#include <iostream>

int main() {
    const int SIZE = 10;
    int k, arr[SIZE] = { 4, 7, -1, 3, -5, 13, 2, 11, 19, 0 };

    std::cout << "Enter a number up to 10: ";
    std::cin >> k;

    std::cout << "\nArray: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << '\n';

    selectionSort(arr, SIZE);

    std::cout << k << " Largest: ";
    for (int i = 1; i <= k; ++i) {
        std::cout << arr[SIZE-i] << " ";
    }
    std::cout << '\n';

    return 0;
}
