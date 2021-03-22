/**
 * Reads list of 20 names from file then sorts names alphabetically using
 *     the selection sort algorithm.
 *
 * @file 11_fStringSelectionSort.cpp
 * @author Timothy Diliberto
 * @version 1.0 3/22/2021
 */

#include <iostream>
#include <fstream>
#include <string>

/**
 * Sorts an array of strings into alphabetical (ascending) order by moving
 *     the smallest of the values toward the front of the array
 * @param arr Array of strings to be sorted
 * @param size Size of the array
 */
void stringSelectionSort(std::string [], int);

/**
 * Reads lines from a file
 *
 * @param arr Array to hold names. Pre-determined size of 20
 */
void readFileToArr(std::string []);



// Main process
int main() {
    const int NUM_NAMES = 20;
    std::string names[NUM_NAMES];

    readFileToArr(names);

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

/**
 * Reads lines from a file
 */
void readFileToArr(std::string arr[]) {
    std::ifstream readFile;
    int index = 0;
    std::string line;

    readFile.open("names.txt");
    if (readFile) {
        std::cout << "File opened successfully, reading data...\n\n";

        while(getline(readFile, line)) {
            arr[index++] = line;
        }

        readFile.close();
    } else {
        std::cout << "Error opening file\n";
    }
}
