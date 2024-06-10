// using_smart_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct sampleStruct {
	int status;
	std::string response;
};

int fun1(string arg1, std::unique_ptr <sampleStruct>& ptr) {
	ptr->status = 200;
	ptr->response = "All Good";
	return 0;
}

int main()
{
    std::cout << "Hello World!\n";
	std::unique_ptr<sampleStruct> ptr(new sampleStruct);

	int result = fun1("arg1", ptr);

	// Use the values in the unique_ptr
	if (ptr) {
		std::cout << "Value in status: " << ptr->status << std::endl;
		std::cout << "Value in Response: " << ptr->response << std::endl;
	}
	else {
		std::cerr << "Error: unique_ptr is empty" << std::endl;
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
