/**
 * Driver program which compares the number of exchanges both bubble sort
 *     and selection sort take to fully sort a 20-element array into
 *     ascending order
 *
 * @file 09_SortBenchmarks.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/17/2021
 */

#include <iostream>

/**
 * Sorts an array by moving the largest element to the back one step at a
 *     time. Repeats for the next largest and so on. Also includes a
 *     counter for number of exchanges made.
 *
 * @param arr Array to be sorted
 * @param size Size of the array
 *
 * @return Number of exchanges needed to sort array
 */
int bubbleSort(int [], int);

/**
 * Sorts an array by moving the smallest element to the front, then
 *     repeating for the next smallest element. Also contains the count of
 *     exchanges
 *
 * @param arr Array to be sorted
 * @param size Size of the array
 *
 * @return Number of exchanges needed to sort array
 */
int selectionSort(int [], int);



// Main process
int main() {
    const int SIZE = 20;
    int exchanges;
    int arr1[SIZE] = { 76, 87, 96, 8, 41, 1, 68, 54, 13, 70, 30, 58, 56,
                      82, 53, 29, 39, 22, 80, 19};
    int arr2[SIZE] = { 76, 87, 96, 8, 41, 1, 68, 54, 13, 70, 30, 58, 56,
                      82, 53, 29, 39, 22, 80, 19};

    exchanges = bubbleSort(arr1, SIZE);
    std::cout << exchanges << " exchanges with bubble sort\n";

    exchanges = selectionSort(arr2, SIZE);
    std::cout << exchanges << " exchanges with selection sort\n";

    return 0;
}

/**
 * Sorts an array by moving the largest element to the back one step at a
 *     time. Repeats for the next largest and so on. Also includes a
 *     counter for number of exchanges made.
 */
int bubbleSort(int arr[], int size) {
    int count = 0;

    for (int max = size - 1; max > 0; --max) {
        for (int index = 0; index < max; ++index) {
            if (arr[index] > arr[index+1]) {
                int temp = arr[index];
                arr[index] = arr[index+1];
                arr[index+1] = temp;
                ++count;
            }
        }
    }
    return count;
} 

/**
 * Sorts an array by moving the smallest element to the front, then
 *     repeating for the next smallest element. Also contains the count of
 *     exchanges
 */
int selectionSort(int arr[], int size) {
    int minIndex,
        minVal,
        count = 0;

    for (int start = 0; start < (size - 1); ++start) {
        minIndex = start;
        minVal = arr[start];

        for (int index = start + 1; index < size; index++) {
            if (arr[index] < minVal) {
                minVal = arr[index];
                minIndex = index;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[start];
        arr[start] = temp;
        ++count;
    }
    return count;
}
