// logging1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://github.com/odundar/simple_cpp_logger/blob/master/Logger.cpp
// https://github.com/odundar/simple_cpp_logger/blob/master/Logger.hpp

#include <iostream>
#include <fstream>
#include <ctime>
#include "Logger2.h"
using namespace std;





int main()
{
    std::cout << "Hello World!\n";

	/*
	shared_ptr<Logger> mylogger = Logger::getInstance();
	cout << mylogger << "Hello World";
	*/

	Logger2 log2 = Logger2::get_instance();
	//log2.init();
	log2.init(INFO, true, false, "abc");
	log2.Info("logging from the class");

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

