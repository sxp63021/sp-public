// json_rapidjson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;

int main()
{
    std::cout << "Hello World! from rapidjson\n";

	// JSON string to parse
	std::string jsonString = R"(
        {
            "name": "John",
            "age": 30,
            "isStudent": true,
            "address": {
                "city": "New York",
                "zipCode": "10001"
            },
            "scores": [85, 90, 95]
        }
    )";

	// Parse the JSON string
	Document document;
	document.Parse(jsonString.c_str());

	// Accessing values
	if (document.IsObject()) {
		std::cout << "Name: " << document["name"].GetString() << std::endl;
		std::cout << "Age: " << document["age"].GetInt() << std::endl;
		std::cout << "Is Student: " << std::boolalpha << document["isStudent"].GetBool() << std::endl;

		const Value& address = document["address"];
		if (address.IsObject()) {
			std::cout << "City: " << address["city"].GetString() << std::endl;
			std::cout << "Zip Code: " << address["zipCode"].GetString() << std::endl;
		}

		const Value& scores = document["scores"];
		if (scores.IsArray()) {
			std::cout << "Scores: ";
			for (SizeType i = 0; i < scores.Size(); i++) {
				std::cout << scores[i].GetInt() << " ";
			}
			std::cout << std::endl;
		}
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
