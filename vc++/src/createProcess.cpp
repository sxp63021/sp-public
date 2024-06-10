// createProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <string>
#include <shlwapi.h> // Include the shlwapi header
#pragma comment(lib, "shlwapi.lib") // Link against shlwapi.lib

using namespace std;

class runProcess {
private:
	
public:
	static bool FileExists(const wchar_t* filePath);
	static std::string ExecuteIpconfigAndGetOutput();
	static std::string ExecuteCommandAndGetOutput(const wchar_t* command);
};

bool runProcess::FileExists(const wchar_t* filePath) {
	return PathFileExists(filePath) == TRUE;
}

std::string runProcess::ExecuteIpconfigAndGetOutput() {

	cout << "in fn ExecuteIpconfigAndGetOutput" << endl;
	SECURITY_ATTRIBUTES saAttr;
	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	HANDLE hChildStdoutRead, hChildStdoutWrite;

	// Create a pipe for the child process's STDOUT
	if (!CreatePipe(&hChildStdoutRead, &hChildStdoutWrite, &saAttr, 0)) {
		return "Error creating pipe";
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// Set up members of the STARTUPINFO structure
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.hStdError = hChildStdoutWrite; // Redirect STDERR to the pipe
	si.hStdOutput = hChildStdoutWrite; // Redirect STDOUT to the pipe
	si.dwFlags |= STARTF_USESTDHANDLES;

	// Create the child process
	//const wchar_t* command = L"ipconfig"; // Note the use of L before the string
	const wchar_t* command = L"C:\\Windows\\System32\\ipconfig.exe"; // Note the use of L before the string - this works

	if (FileExists(command)) {
		std::wcout << L"fn: ExecuteIpconfigAndGetOutput The file exists." << std::endl;
	}
	else {
		std::wcout << L"fn: ExecuteIpconfigAndGetOutput The file does not exist." << std::endl;
	}

	//if (!CreateProcess(NULL, const_cast<LPWSTR>(command), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
	if (!CreateProcess(const_cast<LPWSTR>(command), NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
		return "Error creating process";
	}

	CloseHandle(hChildStdoutWrite);

	// Read the output from the child process's pipe
	DWORD bytesRead;
	char buffer[4096];
	std::string output;

	while (true) {
		if (!ReadFile(hChildStdoutRead, buffer, sizeof(buffer), &bytesRead, NULL) || bytesRead == 0) {
			break;
		}
		output.append(buffer, bytesRead);
	}

	// Close handles
	CloseHandle(hChildStdoutRead);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return output;
}


std::string runProcess::ExecuteCommandAndGetOutput(const wchar_t* command) {
	cout << "Entering function ExecuteCommandAndGetOutput" << endl;
	SECURITY_ATTRIBUTES saAttr;
	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	HANDLE hChildStdoutRead, hChildStdoutWrite;
	//HANDLE hChildStderrRead, hChildStderrWrite;

	// Create a pipe for the child process's STDOUT
	/*
	if (!CreatePipe(&hChildStdoutRead, &hChildStdoutWrite, &saAttr, 0) ||
		!CreatePipe(&hChildStderrRead, &hChildStderrWrite, &saAttr, 0)) {
		*/
	if (!CreatePipe(&hChildStdoutRead, &hChildStdoutWrite, &saAttr, 0)) {
		return "Error creating pipe";
	} else {
		cout << "Created a Pipe" << endl;
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// Set up members of the STARTUPINFO structure
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.hStdError = hChildStdoutWrite; // Redirect STDERR to the pipe
	si.hStdOutput = hChildStdoutWrite; // Redirect STDOUT to the pipe
	si.dwFlags |= STARTF_USESTDHANDLES;

	if (FileExists(command)) {
		std::wcout << L"fn: ExecuteCommandAndGetOutput The file exists." << std::endl;
	} else {
		std::wcout << L"fn: ExecuteCommandAndGetOutput The file does not exist." << std::endl;
	}

	// Create the child process
	//const_cast<wchar_t*>(command), //application name
	if (!CreateProcess(
			const_cast<LPWSTR>(command),
			NULL, // arguments to be passed
			NULL, // Process Attribute
			NULL, // Thread Attribute
			TRUE, // Inheritance Handles
			0, // dwCreationFlags
			NULL, // environment
			NULL,  // current directory
			&si, // startup info
			&pi  // process info
	    )) {
		wprintf(L"Error creating process: %d\n", GetLastError());
		cout << "Not creating the process" << endl;
		return "Error creating process";
	} else {
		cout << "Created the process" << endl;
	}

	// Wait for the process to complete
	//todo - change to a deterministic time, just in case it goes south and causes issues
	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(hChildStdoutWrite);
	//CloseHandle(hChildStderrWrite);

	// Read the output from the child process's pipe
	DWORD bytesRead;
	char buffer[4096];
	std::string output("start in fn ExecuteCommandAndGetOutput ");

	try {
		while (true) {
			if (!ReadFile(hChildStdoutRead, buffer, sizeof(buffer), &bytesRead, NULL) || bytesRead == 0) {
				break;
			}
			output.append(buffer, bytesRead);
		}
	}
	catch (...) {
		cout << "Exception occured - so all output might not be copied" << endl;
	}

	/*
	// Read the error output from the child process's pipe
	while (true) {
		if (!ReadFile(hChildStderrRead, buffer, sizeof(buffer), &bytesRead, NULL) || bytesRead == 0) {
			break;
		}
		output.append(buffer, bytesRead);
	} */

	// Close handles
	CloseHandle(hChildStdoutRead); // 
	//CloseHandle(hChildStderrRead);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	cout << "Exiting function h" << endl;

	std::string ending("End of everything");

	output = output.append(ending);

	return output;
}



int main()
{
    std::cout << "Hello World!123\n";

	// Trying what chatgpt suggested
	//const wchar_t* command = L"C:\\Windows\\System32\\ipconfig.exe";

	if (runProcess::FileExists(command)) {
		std::wcout << L"The file exists." << std::endl;
	}	else {
		std::wcout << L"The file does not exist." << std::endl;
	}

#if 0
	std::string ipconfigOutput = runProcess::ExecuteIpconfigAndGetOutput();
	std::cout << "ipconfig Output:\n" << ipconfigOutput << std::endl;
	//system("pause");
#endif

	// C:\Windows\System32\ipconfig.exe
	std::string output = runProcess::ExecuteCommandAndGetOutput(command);
	std::cout << "Command Output:\n" << output << std::endl;
	std::cout << "Here" << std::endl;
	//system("pause");


	return 0;

}
