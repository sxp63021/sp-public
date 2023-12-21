// ObjectSaveRead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Serializer.h"

int main()
{
    std::cout << "Hello World!\n";

	if (Serializer::serialize(Serializer::mystruct_var, "data.bin")) {
		cout << "Data serialized succcessfully" << endl;
	}
	else {
		cout << "Error" << endl;
		return 1;
	}


	Serializer::MyStruct localreadData;
	if (Serializer::deserialize(localreadData, "data.bin")) {
		cout << "Data deserialzied successfully" << endl;
		cout << "ID: " << localreadData.id << endl;
		cout << "Value: " << localreadData.value << endl;
		cout << "Name: " << localreadData.name << endl;

	}

	return 0;
}
