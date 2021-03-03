/*
 * Program: ReplaceLine.cpp
 * Written by: Timothy Diliberto
 * Replaces a specific line in a file by copying data to a new file and
 * overwriting the specified line
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream writeFile;
	ifstream readFile;
	int line;
	string replacement,
	       text;

	cout << "Which line would you like to replace? ";
	cin >> line;
	cin.ignore();
	cout << "What would you like to replace it with? ";
	getline(cin, replacement);

	writeFile.open("NewLines.txt");
	readFile.open("MultipleLines.txt");

	if (readFile) {
		cout << "File opened successfully. Copying data...\n";

		while(getline(readFile, text)) {
			if (line-- == 1) writeFile << replacement << endl;
			else writeFile << text << endl;
		}

		readFile.close();
	} else
		cout << "Error opening file.\n";

	return 0;
}
