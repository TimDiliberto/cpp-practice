/**
 * Compares the two soring methods, bubble sort and selection sort, to see
 *     in which order and how each sorts identical arrays. The program
 *     prints the array at each iteration of the sorting algorithm to show
 *     what exchange was made.
 *
 * @file 10_SortingOrders.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/21/2021
 */

#include <iostream>

/**
 * Sorts an array by moving the largest element to the back one step at a
 *     time. Repeats for the next largest and so on. Prints the array after  *     each pass of the sort.
 *
 * @param arr Array to be sorted
 * @param size Size of the array
 */
void bubbleSort(int [], int);

/**
 * Sorts an array by moving the smallest element to the front, then
 *     repeating for the next smallest element. Prints the array after each
 *     pass of the sort.
 *
 * @param arr Array to be sorted
 * @param size Size of the array
 */
void selectionSort(int [], int);

/**
 * Prints the given array.
 *
 * @param array The array to be printed
 * @param size The size of the array
 */
void printArray(int [], int);


// Main process
int main() {
    const int SIZE = 8;
    int arr1[SIZE] = { 76, 87, 96, 8, 41, 1, 68, 54 },
        arr2[SIZE] = { 76, 87, 96, 8, 41, 1, 68, 54 };

    std::cout << "Array 1: ";
    printArray(arr1, SIZE);
    bubbleSort(arr1, SIZE);

    std::cout << "\nArray 2: ";
    printArray(arr2, SIZE);
    selectionSort(arr2, SIZE);

    return 0;
}

/**
 * Sorts an array by moving the largest element to the back one step at a
 *     time. Repeats for the next largest and so on. Prints the array after  *     each pass of the sort.
 */
void bubbleSort(int arr[], int size) {
    for (int max = size - 1; max > 0; --max) {
        for (int index = 0; index < max; ++index) {
            if (arr[index] > arr[index+1]) {
                int temp = arr[index];
                arr[index] = arr[index+1];
                arr[index+1] = temp;
                printArray(arr, size);
            }
        }
    }
} 

/**
 * Sorts an array by moving the smallest element to the front, then
 *     repeating for the next smallest element. Prints the array after each
 *     pass of the sort.
 */
void selectionSort(int arr[], int size) {
    int minIndex,
        minVal;

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
        printArray(arr, size);
    }
}

/**
 * Prints the given array.
 */
void printArray(int array[], int size) {
    for (int num = 0; num < size; ++num) {
        std::cout << array[num] << " ";
    }
    std::cout << '\n';
}
