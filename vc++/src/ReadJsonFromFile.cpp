// ReadJsonFromFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"


using namespace rapidjson;
using namespace std;


int main()
{
    std::cout << "Hello World!\n";

	// Open the JSON file
	string filename = "C:\\temp\\data.json"; // data file
	//ifstream file("data.json");
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Could not open the file!" << endl;
		return 1;
	}

	// Read the file into a string
	IStreamWrapper isw(file);
	Document doc;
	doc.ParseStream(isw);

	// Check for parse errors
	if (doc.HasParseError()) {
		cerr << "Error parsing the JSON file!" << endl;
		return 1;
	}

	// Access and print the data from the JSON document
	if (doc.HasMember("id") && doc["id"].IsInt()) {
		cout << "ID: " << doc["id"].GetInt() << endl;
	}
	if (doc.HasMember("value") && doc["value"].IsDouble()) {
		cout << "Value: " << doc["value"].GetDouble() << endl;
	}
	if (doc.HasMember("name") && doc["name"].IsString()) {
		cout << "Name: " << doc["name"].GetString() << endl;
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
