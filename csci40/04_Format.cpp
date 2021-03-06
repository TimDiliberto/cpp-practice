/**
 * Program: Format.cpp
 * Written by: Timothy Diliberto
 * Get two real values from user, print their sum and product in both fixed-
 *     point and scientific notation.
 * Last modified: 3/4/2021
 */

#include <iostream>
#include <iomanip>

int main() {
    double val1, val2;

    std::cout << "Enter two real values: ";
    std::cin >> val1 >> val2;

    std::cout.setf(std::ios::scientific);
    std::cout << std::setprecision(3)
	      << "Scientific:\n" << val1 << '\n' << val2 << '\n';
    std::cout.unsetf(std::ios::scientific);
    std::cout.setf(std::ios::fixed);
    std::cout << "Fixed:\n" << val1 << '\n' << val2 << '\n';

    return 0;
}
