/**
 * Given an array of integers, sorts using selection sort then outputs any
 *     element which has at least two elements greater than itself
 *
 * @file 06_AllButTwoLargest.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/22/2021
 */

#include "../ArrayUtils.h"
#include <iostream>

int main() {
    const int SIZE = 10;
    int k, arr[SIZE] = { 4, 7, -1, 3, -5, 13, 2, 11, 19, 0 };

    std::cout << "Array: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << '\n';

    selectionSort(arr, SIZE);

    for (int i = 0; i < SIZE-2; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
