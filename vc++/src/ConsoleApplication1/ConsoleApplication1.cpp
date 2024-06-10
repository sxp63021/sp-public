// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>  // Include this for InetNtop
#include "LicenseInfo.h"
#include <climits>
#include <string>


using namespace std;
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")  // Link against the ws2_32.lib library

bool writeStringToFile(const std::string& filename, const std::string& data) {
	std::ofstream outputFile;
	outputFile.open(filename, std::ios::app);  // Open the file in append mode

	if (outputFile.is_open()) {
		outputFile << data.c_str();
		outputFile << std::endl;  // Write the data to the file
		outputFile.close();  // Close the file
		return true;  // Return true to indicate success
	}
	else {
		std::cerr << "Failed to open the file for writing." << std::endl;
		return false;  // Return false to indicate an error
	}
}

#if 0
// from chatgpt
std::string getIPAddress() {
	// Variables for holding the result of GetAdaptersAddresses
	ULONG outBufLen = 0;
	PIP_ADAPTER_ADDRESSES pAddresses = nullptr;
	DWORD dwRetVal = 0;

	// Call GetAdaptersAddresses to get the required buffer size
	if (GetAdaptersAddresses(AF_UNSPEC, 0, nullptr, pAddresses, &outBufLen) == ERROR_BUFFER_OVERFLOW) {
		// Allocate memory for the buffer
		pAddresses = reinterpret_cast<IP_ADAPTER_ADDRESSES*>(malloc(outBufLen));

		// Call GetAdaptersAddresses again with the allocated buffer
		if ((dwRetVal = GetAdaptersAddresses(AF_UNSPEC, 0, nullptr, pAddresses, &outBufLen)) == NO_ERROR) {
			// Iterate through the adapters
			for (PIP_ADAPTER_ADDRESSES adapter = pAddresses; adapter != nullptr; adapter = adapter->Next) {
				// Check for IPv4 and IPv6 addresses
				for (PIP_ADAPTER_UNICAST_ADDRESS addr = adapter->FirstUnicastAddress; addr != nullptr; addr = addr->Next) {
					if (addr->Address.lpSockaddr->sa_family == AF_INET) {
						// IPv4 address found
						char ipAddress[INET_ADDRSTRLEN];
						InetNtop(AF_INET, &reinterpret_cast<sockaddr_in*>(addr->Address.lpSockaddr)->sin_addr, ipAddress, INET_ADDRSTRLEN);
						free(pAddresses); // Free the allocated memory
						return ipAddress;
					}
				}
			}
		}
	}

	free(pAddresses); // Free the allocated memory
	return ""; // Return an empty string if no suitable address is found
}


int doit(int, char **)
{
	char ac[80];
	if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
		cerr << "Error " << WSAGetLastError() <<
			" when getting local host name." << endl;
		return 1;
	}
	cout << "Host name is " << ac << "." << endl;

	struct hostent *phe = gethostbyname(ac);
	if (phe == 0) {
		cerr << "Yow! Bad host lookup." << endl;
		return 1;
	}

	for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
		struct in_addr addr;
		memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
		cout << "Address " << i << ": " << inet_ntoa(addr) << endl;
	}

	return 0;
}
#endif

LicenseInfo::licinfo LicenseInfo::lmstatus_current = { "notactivated", "", "", "notactivated", "", "", "notactivated", "", "" };

int main(int argc, char *argv[])
{
    std::cout << "hi Hello World!\n";
	string fname = "C:\\ProgramData\\myfolder\\abc";
	string msg = "Hi";
	int retval = 0;
	//writeStringToFile(fname, msg);
	
	std::string abc("Hi");
	std::cout << "Maximum size of a std::string: " << abc.max_size() << std::endl;

	//LicenseInfo l1 = new LicenseInfo();
	LicenseInfo l1;
#if 1
	// pass1
	//l1.printVals(); // print default values
	l1.writeToFile(LicenseInfo::lmstatus_current); // write default values to file
	l1.lmstatus_current.qxdmKeyIndex = "1"; // change default vals
	l1.lmstatus_current.qxdmKeyVal = "0ea7451b-62fb-11ee-ac5a-026b10d3716b";
	l1.lmstatus_current.qxdmStatus = "Activated";
	l1.writeToFile(l1.lmstatus_current); // write changes values to the file
	l1.printVals();
#else
	//pass 2 - read the file and see if we can see the saved values
	l1.readFromFile();
	LicenseInfo::printVals();
#endif
	// start of getting ip address
#if 0
	std::string ipAddress = getIPAddress();

	if (!ipAddress.empty()) {
		std::cout << "IP Address: " << ipAddress << std::endl;
	}
	else {
		std::cerr << "Error getting IP address." << std::endl;
	}

	// stop of getting ip address
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0) {
		return 255;
	}

	int retval = doit(argc, argv);

	WSACleanup();
#endif
	return retval;
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
