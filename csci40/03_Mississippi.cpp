/**
 * Program: Mississippi.cpp
 * Written by: Timothy Diliberto
 * Print the word 'MISSISSIPPI' using block letters made of asterisks. Each
 *     letter should be its own function
 * Last modified: 3/6/2021
 */

#include <iostream>

void M();
void I();
void S();
void P();

int main() {
    M();
    I();
    S();
    S();
    I();
    S();
    S();
    I();
    P();
    P();
    I();
}

void M() {
    std::cout << "**    **\n"
	      << "***  ***\n"
	      << "** ** **\n"
	      << "**    **\n"
	      << "**    **\n";
}

void I() {
    std::cout << "\n  ****\n"
	      << "   ** \n"
	      << "   ** \n"
	      << "   ** \n"
	      << "  ****\n";
}

void S() {
    std::cout << "\n  **** \n"
	      << " **    \n"
	      << "  ***  \n"
	      << "    ** \n"
	      << " ****  \n";
}

void P() {
    std::cout << "\n *****  \n"
	      << " **  ** \n"
	      << " *****  \n"
	      << " **     \n"
	      << " **     \n";
}
