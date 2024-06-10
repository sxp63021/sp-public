// ping_ips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <Ws2tcpip.h>  // Include for InetPton

// Link against 'Iphlpapi.lib' and 'Ws2_32.lib'

#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "Ws2_32.lib")

std::map<std::string, std::string> responseMap;
// Custom comparison function to compare IP addresses
struct IPComparator {
	bool operator()(const std::string& ip1, const std::string& ip2) const {
		sockaddr_in sa1, sa2;
		std::wstring wideIP1(ip1.begin(), ip1.end());
		std::wstring wideIP2(ip2.begin(), ip2.end());

		InetPton(AF_INET, wideIP1.c_str(), &(sa1.sin_addr));
		InetPton(AF_INET, wideIP2.c_str(), &(sa2.sin_addr));

		return sa1.sin_addr.S_un.S_addr < sa2.sin_addr.S_un.S_addr;
}
};

void pingIP(const std::string& ip) {
#if 0
	std::string pingCommand = "ping -c 4 " + ip; // Adjust the count (-c) as needed
	std::system(pingCommand.c_str());
#else
	// Initialize Winsock
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cerr << "WSAStartup failed\n";
		return;
	}

	// Create an ICMP handle
	HANDLE icmpHandle = IcmpCreateFile();
	if (icmpHandle == INVALID_HANDLE_VALUE) {
		std::cerr << "IcmpCreateFile failed\n";
		WSACleanup();
		return;
	}

	
#if 0
	// Prepare the destination IP address
	ULONG destinationAddress = inet_addr(ip.c_str());

	// Prepare the ICMP echo request
	char requestBuffer[sizeof(ICMP_ECHO_REPLY) + 8];
	PIP_OPTION_INFORMATION options = nullptr;

	// Send the ICMP echo request
	DWORD replySize = IcmpSendEcho(icmpHandle, destinationAddress, requestBuffer, sizeof(requestBuffer),
		options, reinterpret_cast<LPVOID>(&requestBuffer[8]), sizeof(requestBuffer) - 8, 5000);
#endif
	sockaddr_in sa;
	std::wstring wideIP(ip.begin(), ip.end());
	if (InetPton(AF_INET, wideIP.c_str(), &(sa.sin_addr)) != 1) {
		std::cerr << "Invalid IP address: " << ip << std::endl;
		IcmpCloseHandle(icmpHandle);
		WSACleanup();
		return;
	}
	char requestBuffer[sizeof(ICMP_ECHO_REPLY) + 8];
	PIP_OPTION_INFORMATION options = nullptr;

	DWORD replySize = IcmpSendEcho(icmpHandle, sa.sin_addr.S_un.S_addr, nullptr, 0,
		options, reinterpret_cast<LPVOID>(&requestBuffer[8]), sizeof(requestBuffer) - 8, 5000);


	// Check the result
	if (replySize > 0) {
		//std::cout << "IP: " << ip << ", Response: Alive\n";
		responseMap[ip] = "Alive";
	}
	else {
		//std::cerr << "IP: " << ip << ", Response: Unreachable/Timeout\n";
		responseMap[ip] = "Unreachable/Timeout";
	}

	// Clean up
	IcmpCloseHandle(icmpHandle);
	WSACleanup();
}
#endif


int main()
{
    std::cout << "Hello World!\n";
	std::vector<std::string> ipList = {
	"192.168.2.10","192.168.2.11","192.168.2.12","192.168.2.13",
	"192.168.2.14","192.168.2.15","192.168.2.16","192.168.2.17"
	};

	std::vector<std::thread> threads;
	for (const auto& ip : ipList) {
		threads.emplace_back(pingIP, ip);
	}

	for (auto& thread : threads) {
		thread.join();
	}

	// Sort the map by IP address using the custom comparator
	std::map<std::string, std::string, IPComparator> sortedMap(responseMap.begin(), responseMap.end());


	// Print all responses
	std::cout << "Printing all the Responses" << std::endl;
	for (const auto& entry : sortedMap) {
		std::cout << "IP: " << entry.first << ", Response: " << entry.second << std::endl;
	}

	return 0;
}
