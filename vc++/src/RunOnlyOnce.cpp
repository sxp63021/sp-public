// RunOnlyOnce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include "windows.h"

using namespace std;

int main() {
	std::cout << "Hello World" << std::endl;
	const string mutexName = "MyConsoleAppMutex";
	std::wstring stemp = std::wstring(mutexName.begin(), mutexName.end());
	LPCWSTR sw = stemp.c_str();

	//HANDLE hMutex = CreateMutex(NULL, TRUE, "MyConsoleAppMutex");
	HANDLE hMutex = CreateMutex(NULL, TRUE, sw);

	if (hMutex != NULL && GetLastError() != ERROR_ALREADY_EXISTS) {
		// Run your application logic here

		cout << "Console application is running." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();

		CloseHandle(hMutex);
		return 0;
	}
	else {
		cout << "Another instance of the console application is already running." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();

		//CloseHandle(hMutex);
		return 1;
	}
}