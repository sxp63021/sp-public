#include "Serializer.h"

// global init

Serializer::MyStruct Serializer::mystruct_var = { 1001, 45.67, "John Doe" };

bool Serializer::serialize(const MyStruct& data, const string& filename) {
	ofstream outFile(filename, ios::binary);
	if (!outFile.is_open()) {
		cerr << "Error opening file for writing." << endl;
		return false;
	}

	// Write data to the file in a specific order
	outFile.write(reinterpret_cast<const char*>(&data.id), sizeof(data.id));
	outFile.write(reinterpret_cast<const char*>(&data.value), sizeof(data.value));

	size_t nameLength = data.name.length();
	outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
	outFile.write(data.name.c_str(), nameLength);

	outFile.close();
	return true;
}

bool Serializer::deserialize(MyStruct& data, const string& filename) {
	ifstream inFile(filename, ios::binary);
	if (!inFile.is_open()) {
		cerr << "Error opening file for reading." << endl;
		return false;
	}

	// Read data from the file in the same order as written
	inFile.read(reinterpret_cast<char*>(&data.id), sizeof(data.id));
	inFile.read(reinterpret_cast<char*>(&data.value), sizeof(data.value));

	size_t nameLength;
	char* buffer;

	inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
	buffer = new char[nameLength + 1]; // +1 for null terminator
	inFile.read(buffer, nameLength);
	buffer[nameLength] = '\0'; // Add null terminator
	data.name = string(buffer);
	delete[] buffer; nameLength = 0;


	inFile.close();
	return true;
}