/**
 * Driver program to test the string selection sorting method. Main calls
 *     on stringSelectionSort which sorts strings according to the logic
 *     of selection sort
 * @file stringSelectionSort.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/17/2021
 */

#include <iostream>
#include <string>

/**
 * Sorts an array of strings into alphabetical (ascending) order by moving
 *     the smallest of the values toward the front of the array
 * @param arr Array of strings to be sorted
 * @param size Size of the array
 */
void stringSelectionSort(std::string [], int);



// Main process
int main() {
    const int NUM_NAMES = 20;
    std::string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart",
        "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe",
        "Wolfie, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee", "Harrison, Rose",
        "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };

    std::cout << "::UNSORTED NAMES::\n";
    for (std::string name : names) std::cout << name << '\n';

    stringSelectionSort(names, NUM_NAMES);

    std::cout << "\n::SORTED NAMES::\n";
    for (std::string name : names) std::cout << name << '\n';

    return 0;
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
