/**
 * Program: Exams.cpp
 * Written by: Timothy Diliberto
 * Given the weights for exams, calculate and print the weighted average of
 *     each of ten sets of grades, as well as the unweighted average of each
 *     test
 * Last modified: 3/7/2021
 */

#include <iostream>
#include <iomanip>

// Global constants
const int NUM_STUDENTS = 10;
const int NUM_TESTS = 4;

// Function prototypes
void printWSetAverage(int [][NUM_TESTS], double []);
void printUWTestAverage(int [][NUM_TESTS], double []);



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

    printWSetAverage(grades, weights);
    printUWTestAverage(grades, weights);

    return 0;
}

void printWSetAverage(int grades[][NUM_TESTS], double weights[]) {
    std::cout << "---Weighted Averages---\n";
    for (int student = 0; student < NUM_STUDENTS; ++student) {
	double average = 0;

	std::cout << "Student " << student + 1 << ": ";
	for (int test = 0; test < NUM_TESTS; ++test) {
	    average += (grades[student][test] * weights[test]);
	}
	std::cout << std::fixed << std::setprecision(1) << average << '\n';
    }
}

void printUWTestAverage(int grades[][NUM_TESTS], double weights[]) {
    std::cout << "\n---Test Averages---\n";
    for (int test = 0; test < NUM_TESTS; ++test) {
	double sum = 0,
	       average;

        std::cout << "Test " << test + 1 << ": ";
	for (int student = 0; student < NUM_STUDENTS; ++student) {
	    sum += grades[student][test];
	}
        average = sum / NUM_STUDENTS;
	std::cout << std::fixed << std::setprecision(1) << average << '\n';
    }
}
