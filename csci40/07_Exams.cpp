/**
 * Program: Exams.cpp
 * Written by: Timothy Diliberto
 * Given the weights for exams, calculate and print the weighted average of
 *     each of ten sets of grades, as well as the unweighted average of each
 *     test
 * Last modified: 3/7/2021
 */

#include <iostream>

// Global constants
const int NUM_STUDENTS = 10;
const int NUM_TESTS = 4;

// Function prototypes
void printWSetAverage();
void printUWTestAverage();



int main() {
    int grades[NUM_STUDENTS][NUM_TESTS] = {{  90,  85, 90, 95  },
          	                           {  70,  65, 72, 75  },
					   { 100, 100, 95, 100 },
					   {  75,  85, 95, 90  },
					   {  95,  90, 90, 100 },
					   {  50,  35,  0, 0   },
					   {  55,  70, 75, 75  },
					   {  75,  45, 80, 90  },
					   {  90,  90, 95, 95  },
					   {  60,  75, 70, 75  }};
    double weights[NUM_TESTS] = { 0.1, 0.25, 0.3, 0.35 };

    printWSetAverage();
    printUWTestAverage();

    return 0;
}

void printWSetAverage() {
    std::cout << "Called printWSetAverage() successfully!\n";
}

void printUWTestAverage() {
    std::cout << "Called printUWTestAverage() successfully!\n";

}
