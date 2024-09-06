// TestRW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// String variables for holding user inputted filenames
		// And temp for temporarily holding a line of text from file
	string fileNameIn, fileNameOut, temp;
	// ifstream and ofstream for read/write
	ifstream fileIn;
	ofstream fileOut;
	ifstream fileInFromOut;
	// Count number of lines in file for printing line numbers to new file
	int numLines = 0;

	
	// Title block
	cout
		<< "This program takes an input file and outputs the text to a new file" << endl;

	// Prompt user for input filename, try to open file
	cout << "Enter your input filename: ";
	getline(cin, fileNameIn);
	fileIn.open(fileNameIn);

	// If file not found (not opened), print error and re-prompt
	while (!fileIn.is_open()) {
		cout << "File not found. Try again: " << endl;
		getline(cin, fileNameIn);
		fileIn.open(fileNameIn);
	}

	// Prompt user for output file, try to open
	cout << "Enter your output filename: ";
	getline(cin, fileNameOut);
	fileOut.open(fileNameOut);

	// If file not able to be opened (unlikely), print error and re-prompt
	while (!fileIn.is_open()) {
		cout << "Invalid file. Try again: " << endl;
		getline(cin, fileNameOut);
		fileOut.open(fileNameOut);
	}

	// While there is data in the file,
	while (!fileIn.eof()) {
		// Read a line into temp
		getline(fileIn, temp);
		// Increment line counter, then print line number followed by next line of text
		// (prefix increment to allow initialization to zero)
		fileOut << ++numLines << ": " << temp << endl;
	}


	int returnCode = system("echo File Transfer Complete!"); 
	cout<< "returnCode"<< returnCode << endl;
	//cout << "From: " << fileNameIn.c_str << endl;
	//cout << "To: " << fileNameOut.c_str << endl;



	//system("pause");

	
	// Close both files
	fileIn.close();
	fileOut.close();

	// Read outfile to console
	fileInFromOut.open(fileNameOut);
	while (!fileInFromOut.eof()){
		getline(fileInFromOut, temp);
		std::cout << temp << std::endl;
	}
	fileInFromOut.close();

	//system("pause");
	return returnCode;
}
