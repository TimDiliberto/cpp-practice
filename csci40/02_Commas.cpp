/*
 * Program: Commas.cpp
 * Written by: Timothy Diliberto
 * Accept a 7-9 digit number, print commas according to standard convention
 * Last modified 3/6/2021
 */

#include <iostream>

int main() {
    int number,
	first, temp,
	mid, mid_f, mid_m, mid_l,
	last, last_f, last_m, last_l;

    std::cout << "Enter a 7-9 digit number: ";
    std::cin >> number;
    while (number < 1e+06 || number >= 1e+09) {
        std::cout << "Enter a 7-9 digit number: ";
        std::cin >> number;
    }
    std::cin.ignore();

    temp = number / 1000;
    first = temp / 1000;
    mid = temp % 1000;
    mid_f = mid / 100;
    mid_m = (mid / 10) % 10;
    mid_l = mid % 10;
    last  = number % 1000;
    last_f = last / 100;
    last_m = (last / 10) % 10;
    last_l = last % 10;

    std::cout << first << ", " << mid_f << mid_m << mid_l << ", "
	      << last_f << last_m << last_l << '\n';

    return 0;
}
