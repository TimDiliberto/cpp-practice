/**
 * Program: 01_ArrayAllocator.cpp
 * Written by: Timothy Diliberto
 * Dynamically allocates an array of integers. Takes an integer argument
 *     indicating the number of elements. Returns a pointer to the array
 * Last modified: 3/4/2021
 */

#include <iostream>

int main() {
	int *ptr = nullptr;

	int elements;

	std::cout << "How many elements to allocate? "; 
	std::cin >> elements;

	arrAllocator(elements);
}

int *arrAllocator(int elems) {

}
