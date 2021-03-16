/**
 * Includes numerous search and sort algorithms for built-in C++ arrays
 *     which can be used fluidly in other programs
 *
 * @file Arrays.cpp
 * @author Timothy Diliberto
 * @version 2.0 3/14/2021
 */

#include "Arrays.h"

/**
 * Simple swaping function that trades positions of the two arguments
 *
 * @param &a Reference to first element to be swapped
 * @param &b Reference to second element to be swapped
 */
void swap(int &, int &);

//*******************//
// SEARCH ALGORITHMS //
//*******************//
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

//*****************//
// SORT ALGORTIHMS //
//*****************//
void bubbleSort(int arr[], int size) {
    for (int last = size - 1; last > 0; --last) {
        for (int index = 0; index < last; ++index) {
            if (arr[index] > arr[index+1]) {
                swap(arr[index], arr[index+1]);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    int minIndex,
        minVal;

    for (int start = 0; start < size - 1; ++start) {
        minIndex = start;
        minVal = arr[start];
        
        for (int index = start + 1; index < size; ++index) {
            if (arr[index] < minVal) {
                minIndex = index;
                minVal = arr[index];
            }
        }
        swap(arr[start], arr[minIndex]);
    }
}

//*************//
// EXTRA UTILS //
//*************//
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
