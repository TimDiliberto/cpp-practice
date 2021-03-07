/**
 * Program: CheckLetter.cpp
 * Written by: Timothy Diliberto
 * Adds a check letter to each 8-digit number. By splitting into 4 two-digit
 *     numbers and summing those numbers, the remainder after division by 26
 *     will indicate which letter corresponds with the number.
 * Last modified: 3/6/2021
 */

#include <iostream>

int getCheckLetter(int);

int main() {
    int checkNum;
    char checkLetter;

    std::cout << "Enter the check number (8 digits): ";
    std::cin >> checkNum;

    checkLetter = 'A' + getCheckLetter(checkNum);

    std::cout << checkNum << checkLetter << '\n';

    return 0;
}

int getCheckLetter(int num) {
    const int ALPH_NUM = 26;
    int first, last,
	mid_f, mid_l,
	sum, intLetter;

    first = num / 10000;
    mid_f = first % 100;
    first = first / 100;

    last = num % 10000;
    mid_l = last / 100;
    last = last % 100;

    sum = first + mid_f + mid_l + last;
    intLetter = sum % ALPH_NUM;

    return intLetter;
}
