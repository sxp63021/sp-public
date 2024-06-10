// UsingSystemCmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "Hello World!\n";
	// Command to check existence of ipconfig
	int result = system("ipconfig > NUL 2>&1");

	if (result == 0) {
		std::cout << "ipconfig exists!" << std::endl;
	}
	else {
		std::cout << "ipconfig does not exist or could not be executed." << std::endl;
	}

	return 0;
}
