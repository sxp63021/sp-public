#include <iostream>
#include <string>
#include <fstream>

#pragma once

using namespace std;

class LicenseInfo
{
public:
	struct licinfo {
		string qxdmStatus; // activated or notactivated
		string qxdmKeyVal;
		string qxdmKeyIndex;
		string qcatStatus;
		string qcatKeyVal;
		string qcatKeyIndex;
		string pcatStatus;
		string pcatKeyVal;
		string pcatKeyIndex;
	};
	
	static licinfo lmstatus_current;

	static void setLicinfo(licinfo);
	static void setLicinfo_default();
	static void printVals();
	static void writeToFile(licinfo);
	static void readFromFile();
//	static licinfo getLicinfo();

	private:

};

