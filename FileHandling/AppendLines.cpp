/*
 * Program: AppendLine.cpp
 * Written by: Timothy Diliberto
 * Appends a number of lines to a file by copying the original to a new file
 * then adding the new lines
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream writeFile;
	ifstream readFile;
	int lines;
	string text;

	cout << "How many lines would you like to add? ";
	cin >> lines;
	cin.ignore();

	writeFile.open("NewLines.txt");
	readFile.open("MultipleLines.txt");

	if (readFile) {
		cout << "File opened successfully. Copying data...\n";

		while(getline(readFile, text)) {
			writeFile << text << endl;
		}

		readFile.close();

		for (int line = 1; line <= lines; line++) {
			cout << "Write the next line: ";
			getline(cin, text);
			writeFile << text << endl;
		}	
	} else
		cout << "Error opening file.\n";

	return 0;
}
