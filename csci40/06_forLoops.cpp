/**
 * Program: forLoops.cpp
 * Written by: Timothy Diliberto
 * Showcases various functions of the for loop, such as
 *     a) print even numbers between 3 and 43
 *     b) print every third letter, starting at B
 *     c) print numbers 1 thru 20 in one column next to another column of
 *        numbers 20 to 1
 *     d) print every other character in the computer's character set
 * Last modified: 3/6/2021
 */

#include <iostream>

void A();
void B();
void C();
void D();

int main() {
    A();
    B();
    C();
    D();
}

void A() {
    std::cout << "A: ";
    for (int i = 4; i < 43; i=i+2) {
	std::cout << i << " ";
    }
    std::cout << '\n';
}

void B() {
    std::cout << "B: ";
    for (char i = 66; i < 91; i=i+3) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void C() {
    std::cout << "C:\n";
    for (int i = 1; i < 21; ++i) {
        std::cout << i << "   " << 21 - i << '\n';
    }
}

void D() {
    std::cout << "D: ";
    for (char i = 32; i < 127; ++i) {
        if (i % 2 == 0) std::cout << i << " ";
    }
    std::cout << '\n';
}
