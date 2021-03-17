/**
 * Runs a modified version of linearSearch and binarySearch (prefix t_).
 *     A counter is included in each to determine the number of comparison
 *     made to find the given number. Otherwise, -1 is displayed instead.
 *     Program makes a number of calls for each function to show the
 *     benchmarks, or pros and cons, to each search method
 * @file 08_SearchBenchmarks.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/17/2021
 */

#include "../../ArrayUtils.h"
#include <iostream>

/**
 * Searches through an unsorted array, making note of how many comparisons
 *     it has made to either find or pass through the entire array
 *
 * @param arr Array to be searched
 * @param size Size of the array
 * @param val Integer being searched for
 *
 * @return Number of comparisons to find val, or -1 if not present
 */
int t_linearSearch(int [], int, int);

/**
 * Searches through a sorted array using the binary method, making note of
 *     how many comparisons it has made to either find or pass through the
 *     entire array
 *
 * @param arr Array to be searched
 * @param size Size of the array
 * @param val Integer being searched for
 *
 * @return Number of comparisons to find val, or -1 if not present
 */
int t_binarySearch(int [], int, int);



// Main process
int main() {
    const int SIZE = 20;
    int comps;
    int arr[SIZE] = { 76, 87, 96, 8, 41, 1, 68, 54, 13, 70, 30, 58, 56,
                      82, 53, 29, 39, 22, 80, 19};

    for (int i : arr) std::cout << i << " ";
    comps = t_linearSearch(arr, SIZE, 19);
    std::cout << '\n' << comps << " comparisons to find 19\n";
    comps = t_linearSearch(arr, SIZE, 13);
    std::cout << comps << " comparisons to find 13\n";
    comps = t_linearSearch(arr, SIZE, 70);
    std::cout << comps << " comparisons to find 70\n";
    comps = t_linearSearch(arr, SIZE, 76);
    std::cout << comps << " comparisons to find 76\n";
    comps = t_linearSearch(arr, SIZE, 87);
    std::cout << comps << " comparisons to find 87\n";
    comps = t_linearSearch(arr, SIZE, 82);
    std::cout << comps << " comparisons to find 82\n";

    selectionSort(arr, SIZE);
    std::cout << "\nselectionSort called!\n";

    for (int i : arr) std::cout << i << " ";
    comps = t_binarySearch(arr, SIZE, 19);
    std::cout << '\n' << comps << " comparisons to find 19\n";
    comps = t_binarySearch(arr, SIZE, 13);
    std::cout << comps << " comparisons to find 13\n";
    comps = t_binarySearch(arr, SIZE, 70);
    std::cout << comps << " comparisons to find 70\n";
    comps = t_binarySearch(arr, SIZE, 76);
    std::cout << comps << " comparisons to find 76\n";
    comps = t_binarySearch(arr, SIZE, 87);
    std::cout << comps << " comparisons to find 87\n";
    comps = t_binarySearch(arr, SIZE, 82);
    std::cout << comps << " comparisons to find 82\n";

    return 0;
}

/**
 * Searches through an unsorted array, making note of how many comparisons
 *     it has made to either find or pass through the entire array
 */
int t_linearSearch(int arr[], int size, int val) {
    int index = 0,
        pos = -1,
        count = 0;
    bool found = false;

    while (!found && index < size) {
        if (arr[index] == val) {
            found = true;
            pos = index;
        }
        ++index;
        ++count;
    }
    if (found) return count;
    else return pos;
} 

/**
 * Searches through an sorted array using the binary method, making note of
 *     how many comparisons it has made to either find or pass through the
 *     entire array
 */
int t_binarySearch(int arr[], int size, int val) {
    int first = 0,
        last = size - 1,
        mid,
        pos = -1,
        count = 0;
    bool found = false;

    while (!found && first <= last) {
        mid = (first + last) / 2;
        
        if (arr[mid] == val) {
            found = true;
            pos = mid;
        } else if (arr[mid] > val) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
        ++count;
    }

    if (found) return count;
    else return pos;
}
