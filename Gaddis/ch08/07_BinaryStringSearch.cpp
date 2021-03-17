/**
 * Driver program to test the string binary search method. First program
 *     sort using selection sort, then display the names with their new
 *     indices for ease of viewing. Finally, use binary search to determine
 *     if a given string is in the array and output the results.
 * @file 07_BinaryStringSearch.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/17/2021
 */

#include <iostream>
#include <string>

/**
 * Searches through an array of strings starting from the middle then
 *     working its way outwards depending on whether or not the sought
 *     after string is greater or less than the current middle.
 * 
 * @param arr Array of strings to be searched through
 * @param size Size of the array
 * @param val The string being searched for
 *
 * @return Index of searched string in the array, or -1 if not present
 */
int binarySearch(std::string [], int, std::string);

/**
 * Sorts an array of strings into alphabetical (ascending) order by moving
 *     the smallest of the values toward the front of the array
 *
 * @param arr Array of strings to be sorted
 * @param size Size of the array
 */
void stringSelectionSort(std::string [], int);



// Main process
int main() {
    const int NUM_NAMES = 20;
    int index;
    std::string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart",
        "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe",
        "Wolfie, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee", "Harrison, Rose",
        "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };
    
    stringSelectionSort(names, NUM_NAMES);

    for (int i = 0; i < NUM_NAMES; ++i) {
        std::cout << i << ". " << names[i] << '\n';
    }

    index = binarySearch(names, NUM_NAMES, "Stamey, Marty");
    std::cout << "\n'Stamey, Marty' was found at index " << index << '\n';

    index = binarySearch(names, NUM_NAMES, "Holland, Beth");
    std::cout << "\n'Holland, Beth' was found at index " << index << '\n';

    index = binarySearch(names, NUM_NAMES, "Diliberto, Tim");
    std::cout << "\n'Diliberto, Tim' was found at index " << index << '\n';

    return 0;
}

/**
 * Searches through an array of strings starting from the middle then
 *     working its way outwards depending on whether or not the sought
 *     after string is greater or less than the current middle.
 */
int binarySearch(std::string arr[], int size, std::string val) {
    int first = 0,
        last = size - 1,
        mid,
        pos = -1;
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
    }
    return pos;
}

/**
 * Sorts an array of strings into alphabetical (ascending) order by moving
 *     the smallest of the values toward the front of the array
 */
void stringSelectionSort(std::string arr[], int size) {
    int minIndex;
    std::string minVal;

    for (int start = 0; start < size; ++start) {
        minIndex = start;
        minVal = arr[start];

        for (int index = start+1; index < size; ++index) {
            if (arr[index] < minVal) {
                minIndex = index;
                minVal = arr[index];
            }
        }
        
        std::string temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
