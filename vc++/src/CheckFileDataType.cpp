// CheckFileDataType.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "rapidjson/document.h"

using namespace rapidjson;
using namespace std;

// Function to read the content of a file into a string
string readFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Could not open file");
	}
	stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

// Function to determine if the content is JSON
bool isJson(const string& content) {
	Document doc;
	return !doc.Parse(content.c_str()).HasParseError();
}


int main()
{
    std::cout << "Hello World!\n";

	string filename = "C:\\temp\\data.bin"; // data file
	string filename_json_singleln = "C:\\temp\\file.json"; // json file
	string filename_json_multiln = "C:\\temp\\file.json.ml"; // json file

	try {
		string content = readFile(filename);

		if (isJson(content)) {
			cout << "The file " + filename + " contains JSON content." << endl;
		}
		else {
			cout << "The file " + filename + " does not contain JSON content." << endl;
		}

		// second try
		string content1 = readFile(filename_json_singleln);

		if (isJson(content1)) {
			cout << "The file " + filename_json_singleln + " contains JSON content." << endl;
		}
		else {
			cout << "The file " + filename_json_singleln + " does not contain JSON content." << endl;
		}

		// third type

		string content2 = readFile(filename_json_multiln);

		if (isJson(content2)) {
			cout << "The file " + filename_json_multiln + " contains JSON content." << endl;
		}
		else {
			cout << "The file " + filename_json_multiln + " does not contain JSON content." << endl;
		}
	}


	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
