/*
 * Program: ReadFile.cpp
 * Written by: Timothy Diliberto
 * Reads and displays the contents of a file and how many lines, words, and
 * characters it contains
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream readFile;
	int numLines = 0,
	    numWords = 0,
	    numChars = 0;
	string text;

	// Get number of words and characters
	readFile.open("MultipleLines.txt");

	if (readFile) {
		while(readFile >> text) {
			numWords++;
			numChars += text.length();
		}

		readFile.close();
	} else
		cout << "An error occurred, please try again.\n";

	// Get number of lines, display text and data
	readFile.open("MultipleLines.txt");

	if (readFile) {
		cout << "File opened successfully. Reading data...\n"

		     << "\nMultipleLine.txt Contents:\n";

		while(getline(readFile, text)) {
			cout << text << endl;
			numLines++;
		}

		readFile.close();

		cout << "\nThis text contains " << numLines << " lines.\n"
		     << "                   " << numWords << " words.\n"
		     << "                   " << numChars << " chars.\n";
	} else
		cout << "Error opening file.\n";

	return 0;
}
