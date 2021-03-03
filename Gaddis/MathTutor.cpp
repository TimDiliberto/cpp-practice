/*
 * Program: MathTutor.cpp
 * Written by: Timothy Diliberto
 * Gives students addition problems with numbers between 0 and 999, with
 * solutions
 * Last modified: 12/06/2020
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	const int MIN = 0,
	      	  MAX = 999;
	int firstNum,
	    secondNum,
	    solution,
	    answer;
	unsigned seed = time(0);

	srand(seed);

	firstNum = (rand() % (MAX - MIN + 1)) + MIN;
	secondNum = (rand() % (MAX - MIN + 1)) + MIN;
	solution = firstNum + secondNum;

	cout << "Press 'Enter' to check\n"
	     << setw(4) << firstNum << endl
	     << "+" << setw(3) << secondNum << endl
	     << "____\n";
	cin >> answer;

	if (answer != solution)
		cout << "\nThat is incorrect.\n"
		     << "The answer is " << solution << endl;
	else
		cout << "\nCongratulations, that's correct!\n";

	return 0;
}
