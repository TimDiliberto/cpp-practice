/*
 * Program: WriteFile.cpp
 * Written by: Timothy Diliberto
 * Writes a line to a file
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream writeFile("SingleLine.txt");
	string line;

	cout << "Write a line to the file: ";
	getline(cin, line);

	writeFile << line << endl;

	writeFile.close();
	cout << "File saved successfully\n";

	return 0;
}
