// SaveStructToJsonFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

struct MyStruct {
	int id;
	double value;
	string name;
};

void serializeToJson(const MyStruct& data, const string& filename) {
	// Create a RapidJSON document
	Document doc;
	doc.SetObject();

	// Get the allocator
	Document::AllocatorType& allocator = doc.GetAllocator();

	// Add members to the document
	doc.AddMember("id", data.id, allocator);
	doc.AddMember("value", data.value, allocator);

	// For strings, we need to use SetString and pass the allocator
	Value name;
	name.SetString(data.name.c_str(), static_cast<SizeType>(data.name.length()), allocator);
	doc.AddMember("name", name, allocator);

	// Convert the document to a JSON string
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	doc.Accept(writer);

	// Write the JSON string to a file
	ofstream ofs(filename);
	if (!ofs.is_open()) {
		cerr << "Could not open the file for writing!" << endl;
		return;
	}
	ofs << buffer.GetString();
	ofs.close();
}


int main()
{
    std::cout << "Hello World!\n";

	// Create an instance of the struct
	MyStruct data = { 1001, 45.67, "John Doe" };

	// Serialize the struct to a JSON file
	serializeToJson(data, "output.json");

	cout << "Data has been serialized to output.json" << endl;

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
