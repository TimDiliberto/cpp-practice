/*
 * Program: WriteMultipleLines.cpp
 * Written by: Timothy Diliberto
 * Writes multiple lines to a file
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream writeFile("MultipleLines.txt");
	int numLines;
	string text;

	cout << "How many lines do you want to write? ";
	cin >> numLines;
	cin.ignore();

	for (int line = 1; line <= numLines; line++) {
		cout << "Write a line to the file: ";
		getline(cin, text);
		writeFile << text << endl;
	}

	writeFile.close();
	cout << "File saved successfully\n";

	return 0;
}
