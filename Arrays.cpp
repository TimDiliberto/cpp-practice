/*
 * Program: Arrays.cpp
 * Written by Timothy Diliberto
 * Contains various utility functions for arrays, such as searching and sorting
 * Last modified 12/13/2020
 */

#include "Arrays.h"

/* * * * * * * * * * *
 * SEARCH ALGORITHMS *
 * * * * * * * * * * */

int linearSearch(auto array[], int size, auto value) {
	int index = 0,
	    position = -1;
	bool found = false;

	while (!found && index < size) {
		if (array[index] == value) {
			position = index;
			found = true;
		}
		index++;
	}

	return position;
}

int binarySearch(auto array[], int size, auto value) {
	int first = 0,
	    last = size - 1,
	    middle,
	    position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		
		if (array[middle] == value) {
			position = middle;
			found = true;
		} else if (array[middle] > value) 
			last = middle - 1;
		else first = middle + 1;
	}

	return position;
}



/* * * * * * * * * * *
 * SORTING ALGORITHMS *
 * * * * * * * * * * */

void bubbleSort(auto array[], int size) {
	int maxIndex,
	    index;

	for (maxIndex = size - 1; maxIndex > 0; maxIndex--) {
		for (index = 0; index < maxIndex; index++) {
			if (array[index] > array[index + 1])
				std::swap(array[index], array[index + 1]);
		}
	}
}

void selectionSort(auto array[], int size) {
	
}
