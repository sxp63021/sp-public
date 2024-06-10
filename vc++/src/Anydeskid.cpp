// Anydeskid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <string>
#include <filesystem>
#include <codecvt>
#include <ShlObj.h>
#include <Shlwapi.h> // Include the header for PathFileExists
#pragma comment(lib, "Shlwapi.lib") // Link against the Shlwapi library

void removeSpaces(std::string &str) {
	str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
}

std::string GetBiosSerialNumber() {
	std::array<char, 128> buffer;
	std::string result;

	FILE* pipe = _popen("wmic bios get serialnumber", "r");
	if (!pipe) {
		std::cerr << "Error: _popen failed." << std::endl;
		return "";
	}

	while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) != nullptr) {
		result += buffer.data();
	}

	_pclose(pipe);

	// Remove unwanted characters (e.g., newline) from the result
	result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
	result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());

	// Remove the header and trim the serial number
	size_t pos = result.find("SerialNumber");
	if (pos != std::string::npos) {
		result = result.substr(pos + 12); // Length of "SerialNumber" plus spaces
	}

	// Remove spaces from the string
	removeSpaces(result);

	return result;
}

std::string GetAnyDeskId() {

	// start
	wchar_t userProfile[MAX_PATH];

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, userProfile))) {
		// Now userProfile contains the path to the user's profile directory
		std::wcout << L"User Profile Directory: " << userProfile << std::endl;

		// If you need the Roaming folder specifically
		std::wstring roamingPath = userProfile;
		roamingPath += L"\\AppData\\Roaming";
		std::wcout << L"Roaming Directory: " << roamingPath << std::endl;
	}
	else {
		std::cerr << "Failed to get the user's profile directory." << std::endl;
		return "";
	}	
	// stop

	//std::string cfgfile = "C:\\Users\\%USERPROFILE%\\AppData\\Roaming\\AnyDesk\\system.conf";
	// Convert wide string to narrow string
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

	std::string cfgfile = converter.to_bytes(userProfile);
		cfgfile += "\\AppData\\Roaming\\AnyDesk\\system.conf";

	// Convert to wide string
	//std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::wstring wideStr = converter.from_bytes(cfgfile);

	if (PathFileExists(wideStr.c_str()) == TRUE) {
		std::cout << "File exists." << std::endl;
	}
	else {
		std::cerr << "File does not exist or cannot be accessed." << std::endl;
		return "";
	}

	std::ifstream configFile(cfgfile);

	if (!configFile.is_open()) {
		std::cerr << "Error opening AnyDesk configuration file." << std::endl;
		return "";
	}

	std::string line;
	while (std::getline(configFile, line)) {
		size_t pos = line.find("ad.anynet.id");
		if (pos != std::string::npos) {
			// Extract the AnyDesk ID (assuming a specific format, adjust as needed)
			std::string anyDeskId = line.substr(pos + 13);  // "AnyDeskId=" is 10 characters
			configFile.close();
			return anyDeskId;
		}
	}

	configFile.close();
	std::cerr << "AnyDesk ID not found in the configuration file." << std::endl;
	return "";
}

// Read in 
std::string GetAnyDeskId2() {

	std::wstring anydeskId;

	// Path to the AnyDesk registry key
	std::string cfgfile = "C:\\ProgramData\\AnyDesk\\system.conf";

	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

	// Convert to wide string
	//std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::wstring wideStr = converter.from_bytes(cfgfile);

	if (PathFileExists(wideStr.c_str()) == TRUE) {
		std::cout << "File exists." << std::endl;
	}
	else {
		std::cerr << "File does not exist or cannot be accessed." << std::endl;
		return "";
	}

	std::ifstream configFile(cfgfile);

	if (!configFile.is_open()) {
		std::cerr << "Error opening AnyDesk2 configuration file." << std::endl;
		return "";
	}

	std::string line;
	while (std::getline(configFile, line)) {
		size_t pos = line.find("ad.anynet.id");
		if (pos != std::string::npos) {
			// Extract the AnyDesk ID (assuming a specific format, adjust as needed)
			std::string anyDeskId = line.substr(pos + 13);  // "AnyDeskId=" is 10 characters
			configFile.close();
			return anyDeskId;
		}
	}

	configFile.close();
	std::cerr << "AnyDesk ID not found in the configuration file." << std::endl;
	return "";

}

int main() {
	// Get the AnyDesk ID
	std::string anyDeskId = GetAnyDeskId();

	if (!anyDeskId.empty()) {
		std::cout << "AnyDesk ID: " << anyDeskId << std::endl;
	}
	else {
		std::cerr << "Error getting AnyDesk ID." << std::endl;
	}

	std::string anyDeskId2 = GetAnyDeskId2();

	if (!anyDeskId2.empty()) {
		std::cout << "AnyDesk ID2: " << anyDeskId2 << std::endl;
	}
	else {
		std::cerr << "Error getting AnyDesk ID2." << std::endl;
	}


	std::string win_serial_number = GetBiosSerialNumber();
	if (!win_serial_number.empty()) {
		std::cout << "Windows Serial Number: " << win_serial_number << std::endl;
	}
	else {
		std::cerr << "Error getting Windows Serial Number" << std::endl;
	}

#if 0
	std::wstring anydeskId = GetAnyDeskId();

	// Print the AnyDesk ID
	if (!anydeskId.empty()) {
		std::wcout << L"AnyDesk ID: " << anydeskId << std::endl;
	}
	else {
		std::wcerr << L"Error getting AnyDesk ID." << std::endl;
	}

#endif
	return 0;
}

/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
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
*/