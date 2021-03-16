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

int binarySearch(int arr[], int size, int val) {
    int first = 0,
        last = size - 1,
        mid,
        pos = -1;
    bool found = false;

    while (!found && first <= last) {
        mid = (last + first) / 2;
        if (arr[mid] == val) {
            found = true;
            pos = mid;
        } else if (arr[mid] > val) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return pos;
}

// SORT ALGS
void bubbleSort(int arr[], int size) {
    for (int last = size - 1; last > 0; --last) {
        for (int i = 0; i < last; ++i) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 2; ++i) {
        int minIndex = i;
        int minVal = arr[i];
        for (int j = i+1; j < size - 1; ++j) {
            if (arr[j] < arr[i]) {
                minVal = arr[j];
                minIndex = j;
            }
        }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
    }
}
