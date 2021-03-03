/*
 * Program: DeleteLine.cpp
 * Written by: Timothy Diliberto
 * Deletes the specified line in the text by copying all but that line to a new
 * file
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
	string text;

	cout << "Which line would you like to delete? ";
	cin >> line;

	writeFile.open("NewLines.txt");
	readFile.open("MultipleLines.txt");

	if (readFile) {
		cout << "File opened successfully. Copying data...\n";

		while(getline(readFile, text)) {
			if (line-- == 1) continue;
			else writeFile << text << endl;
		}

		readFile.close();
	} else
		cout << "Error opening file.\n";

	return 0;
}
