/**
 * Given an array of integers, sorts using selection sort then outputs the
 *     three largest element to the terminal
 *
 * @file 01_LargestElem.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/22/2021
 */

#include "../ArrayUtils.h"
#include <iostream>

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 4, 7, -1, 3, -5, 13, 2, 11, 19, 0 };

    std::cout << "Array: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << '\n';

    selectionSort(arr, SIZE);

    std::cout << "1st Largest: " << arr[SIZE-1] << '\n';
    std::cout << "2nd Largest: " << arr[SIZE-2] << '\n';
    std::cout << "3rd Largest: " << arr[SIZE-3] << '\n';

    return 0;
}
