#include "LicenseInfo.h"

void LicenseInfo::setLicinfo(licinfo input) {

	lmstatus_current = input;
	return;
}

void LicenseInfo::setLicinfo_default() {
	struct licinfo input1 = {
							  "notactivated", "none", "none",
							  "notactivated", "none", "none",
							  "notactivated", "none", "none"
	};
	lmstatus_current = input1;
}

void LicenseInfo::printVals() {
	string printstr;
	cout << "Printing vals" << endl;

	std::cout << LicenseInfo::lmstatus_current.qxdmStatus << endl;
	std::cout << LicenseInfo::lmstatus_current.qcatStatus << endl;
	std::cout << LicenseInfo::lmstatus_current.pcatStatus << endl;

	printstr = "qxdmStatus: " + lmstatus_current.qxdmStatus;
	printstr += " qxdmKeyVal: " + lmstatus_current.qxdmKeyVal;
	printstr += " qxdmKeyIndex: " + lmstatus_current.qxdmKeyIndex;
	cout << printstr << endl;

	printstr = "qcatStatus: " + lmstatus_current.qcatStatus;
	printstr += " qcatKeyVal: " + lmstatus_current.qcatKeyVal;
	printstr += " qcatKeyIndex: " + lmstatus_current.qcatKeyIndex;
	cout << printstr << endl;

	printstr = "pcatStatus: " + lmstatus_current.pcatStatus;
	printstr += " pcatKeyVal: " + lmstatus_current.pcatKeyVal;
	printstr += " pcatKeyIndex: " + lmstatus_current.pcatKeyIndex;
	cout << printstr << endl;

	cout << "End of Printing vals" << endl;
}

void LicenseInfo::writeToFile(licinfo data) {
	// Open a file stream
	ofstream outFile("c:\\temp\\data.bin", ios::binary);
	//ofstream outFile("c:\\temp\\data.bin", ios::text);

	if (outFile.is_open()) {
		// Write the struct data to the file
		outFile.write(reinterpret_cast<const char*>(&data), sizeof(data));

		// Close the file stream
		outFile.close();
		cout << "Struct data has been written to file successfully." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
}

void LicenseInfo::readFromFile() {

	licinfo data;

	ifstream inFile("c:\\temp\\data.bin", ios::binary);

	if (inFile.is_open()) {
		// Read the content of the file into the struct
		inFile.read(reinterpret_cast<char*>(&data), sizeof(data));

		// Check if reading was successful and output the read data
		if (inFile) {
			cout << "Read struct data from file:" << endl;
			cout << "qxdmkeyindex: " << data.qxdmKeyIndex << endl;
			cout << "qxdmKeyVal: " << data.qxdmKeyVal << endl;
			cout << "qxdmKeyStatus: " << data.qxdmStatus << endl;
			lmstatus_current = data;
		}
		else {
			cout << "Error reading from file." << endl;
		}

		// Close the file stream
		inFile.close();
	}
}

/*
LicenseInfo::licinfo LicenseInfo::getLicinfo() {
	return classvarlic;
}

*/