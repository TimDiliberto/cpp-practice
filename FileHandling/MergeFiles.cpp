/*
 * Program: MergeFiles.cpp
 * Written by: Timothy Diliberto
 * Merges files contents from two separate files to a new file
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

	writeFile.open("MergedLines.txt");
	readFile.open("SingleLine.txt");

	if (readFile) {
		cout << "File opened successfully. Copying data...\n";

		while(getline(readFile, text)) {
			writeFile << text << endl;
		}

		readFile.close();
	} else
		cout << "Error opening file.\n";

	readFile.open("MultipleLines.txt");

	if (readFile) {
		cout << "File opened successfully. Copying data...\n";

		while(getline(readFile, text)) {
			writeFile << text << endl;
		}

		readFile.close();
		writeFile.close();
	} else
		cout << "Error opening file.\n";

	return 0;
}
