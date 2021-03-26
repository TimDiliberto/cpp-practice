/**
 * Given an array of integers, sorts using selection sort then outputs the
 *     two smallest element to the terminal
 *
 * @file 05_SmallestTwo.cpp
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

    std::cout << "1st Smallest: " << arr[0] << '\n';
    std::cout << "2nd Smallest: " << arr[1] << '\n';

    return 0;
}
