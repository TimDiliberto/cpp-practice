#ifndef ARRAYS_H
#define ARRAYS_H

/**
 * Sequentially searches through an array for a specified value
 *
 * @param arr The array to be searched
 * @param size The size of the array
 * @param val The value being searched for
 *
 * @return Index of searched value. If not in array, return -1
 */
int linearSearch(int [], int, int);

/**
 * Searches through an array by checking the middle element then
 * determining whether the sought after value will be before or after
 * the middle element
 *
 * @param arr The array to be searched
 * @param size The size of the array
 * @param val The value being searched for
 *
 * @return Index of searched value. If not in array, return -1
 */
int binarySearch(int [], int, int);

/**
 * Sorts the given array in ASCENDING order by shifting larger elements
 * toward the end of the array, one at a time
 *
 * @param arr The array to be sorted
 * @param size The size of the array
 */
void bubbleSort(int [], int);

/**
 * Sorts the given array in ASCENDING order by sending the smallest
 * element to the first position then sending each next greatest element
 * to the following position
 *
 * @param arr The array to be sorted
 * @param size The size of the array
 */
void selectionSort(int [], int);

#endif
