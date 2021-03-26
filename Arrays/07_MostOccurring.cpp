/**
 * Iterates through an array making comparisons to determine which element
 *     occurs the most
 *
 * @file 07_MostOccurring.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/25/2021
 */

#include "../ArrayUtils.h"
#include <iostream>

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 4, 7, -1, 3, -5, -1, 2, 3, 3, 0 },
        maxCount = 0,
        mostCommon;

    std::cout << "Array: ";
    for (int elem : arr) std::cout << elem << " ";
    std::cout << '\n';

    for (int i = 0; i < SIZE-2; ++i) {
        int count = 1;

        for (int j = i+1; j < SIZE - 1; ++j) {
            if (arr[i] == arr[j]) {
                ++count;
            }
        }
        
        if (count > maxCount) {
            mostCommon = arr[i];
        }
    }

    std::cout << "Most Occurring Number: " << mostCommon << '\n';

    return 0;
}
