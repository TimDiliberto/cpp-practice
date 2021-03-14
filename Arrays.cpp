/**
 * Program: Arrays.cpp
 * Written by: Timothy Diliberto
 * Includes numerous search and sort algorithms for built-in C++ arrays
 *     which can be used fluidly in other programs.
 * Last modified: 3/14/2021
 */

#include "Arrays.h"

// SEARCH ALGORITHMS
int linearSearch(int arr[], int size, int val) {
    int index = 0,
        pos = -1;
    bool found = false;

    while (!found && index < size) {
        if (arr[index] == val) {
            found = true;
            pos = index;
        }
        ++index;
    }
    return pos;
}
