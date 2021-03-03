/*
 * Program: ReadFile.cpp
 * Written by: Timothy Diliberto
 * Reads the contents of a file
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream readFile;
	string line;

	readFile.open("SingleLine.txt");
	if (readFile) {
		cout << "File opened successfully. Reading data...\n"

		     << "\nSingleLine.txt Contents:\n";

		while(getline(readFile, line))
			cout << line << endl;

		readFile.close();
	} else
		cout << "Error opening file.\n";

	return 0;
}
