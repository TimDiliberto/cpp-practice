/**
 * Dynamically allocates an array to hold a user-defined number of test
 *     scores. Calls a function to sort the array, then another to find the
 *     average of the test scores.
 *
 * @file 02_TestScores.cpp
 * @author Timothy Diliberto
 * @version 1.0 5/25/2021
 */

#include <iostream>
#include "../../ArrayUtils.h" // For selectionSort function

double arrAverage(int*, int);

int main() {
    int numScores;
    int *scores = nullptr;
    double average;
    
    std::cout << "How many scores to enter: ";
    std::cin >> numScores;

    scores = new int[numScores];

    for (int i = 0; i < numScores; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> i[scores];

        while (i[scores] < 0 || i[scores] > 100) {
            std::cout << "Enter a score between 0 and 100: ";
            std::cin >> i[scores];
        }
    }

    selectionSort(scores, numScores);

    for (int i = 0; i < numScores; ++i) {
        std::cout << i[scores] << " ";
    }
    std::cout << '\n';

    average = arrAverage(scores, numScores);

    std::cout << "Test Score Average: " << average << '\n';

    delete scores;
    scores = nullptr;

    return 0;
}

double arrAverage(int *arr, int size) {
    int sum = 0;
    double average;

    for (int i = 0; i < size; ++i) {
        sum += i[arr];
    }

    average = sum / size;

    return average;
}
