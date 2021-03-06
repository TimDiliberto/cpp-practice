/**
 * Program: 05_MonkeyBusiness.cpp
 * Written by: Timothy Diliberto
 * Stores the data for how many pounds of food monkeys at a zoo eat each week.
 *     Using a two-dimensional 3x5 array, the user will input the data then a
 *     report will be created including:
 *     - Average food eaten by day between all monkeys
 *     - Least amount of food eaten by a single monkey
 *     - Most amount of food eaten by a single monkey
 * Last modified: 3/5/2021
 */

#include <iostream>
#include <iomanip>

int main() {
    const int MONKEYS = 3,
	      DAYS = 5;
    std::string days[DAYS] = { "MON", "TUE", "WED", "THUR", "FRI" };
    double lbsEaten[MONKEYS][DAYS];

    std::cout << "Enter pounds of food eaten by each monkey for every day of "
	      << "the week:\n";

    for (int monkey = 0; monkey < MONKEYS; ++monkey) {
        for (int day = 0; day < DAYS; ++day) {
	    std::cout << "Monkey " << monkey + 1 
		      << ", Day " << day + 1 << ": ";
	    std::cin >> lbsEaten[monkey][day];
	}
    }

    for (int i = 0; i < MONKEYS; ++i) {
	std::cout << "M" << i << ": ";

	for (int j = 0; j < DAYS; ++j) {
            std::cout << std::setprecision(1) << std::fixed
		      << std::setw(4) << lbsEaten[i][j] << " ";
	}
	std::cout << '\n';
    }

    return 0;
}
