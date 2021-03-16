#ifndef ARRAYS_H
#define ARRAYS_H

/**
 * Sequentially searches through an array for a specified value
 * @param arr The array to be searched
 * @param size The size of the array
 * @param val The value being searched for.
 * @return Index of searched value. If not in array, return -1.
 */
int linearSearch(int [], int, int);

int binarySearch(int [], int, int);

void bubbleSort(int [], int);

void selectionSort(int [], int);

#endif
