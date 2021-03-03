/*
 * Program: DeleteFile.cpp
 * Written by: Timothy Diliberto
 * Deletes the specified file
 * Last modified 12/06/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	if (remove("CopyMultipleLines.txt"))
		cout << "File deletion failed.\n";
	else
		cout << "File deleted successfully\n";

	return 0;
}
