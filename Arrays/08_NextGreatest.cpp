/**
 *
 * @file 08_NextGreatest.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/28/2021
 */

#include "../ArrayUtils.h"
#include <iostream>

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 3, 0, 3, 3, 4, 15, 27, 67, 17, 19 };
    int greatest;

    for (int elem : arr) std::cout << elem << " "
    std::cout << '\n';

    for (int i = 0; i < SIZE - 1; ++i) {
        int curr =  arr[i],
            nextIndex = i+1;
        while (arr[nextIndex] <= curr) {
            ++nextIndex;
        }
        if (
        greatest = arr[nextIndex];
        std::cout << "Next Greatest from " << curr << " : " << greatest
                  << '\n';
    }

    std::cout << "Greatest element: " << greatest << '\n';

    return 0;
}
