// json_parsing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

// Helper function to trim whitespace from the beginning and end of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

#if 0
// Function to parse JSON recursively
void parseJson(const std::string& json, std::map<std::string, std::string>& keyValueMap) {
    size_t pos = 0;
    size_t len = json.length();
    while (pos < len) {
        size_t startKey = json.find('"', pos);
        if (startKey == std::string::npos)
            break;
        size_t endKey = json.find('"', startKey + 1);
        if (endKey == std::string::npos)
            break;
        std::string key = trim(json.substr(startKey + 1, endKey - startKey - 1));

        size_t startValue = json.find(':', endKey);
        if (startValue == std::string::npos)
            break;
        size_t endValue = json.find_first_of("{[\",}", startValue);
        if (endValue == std::string::npos)
            break;
        std::string value = trim(json.substr(startValue + 1, endValue - startValue - 1));

        keyValueMap[key] = value;

        pos = endValue;
    }
}
#endif

// second attempt
#if 0
void parseJson(const std::string& json, std::map<std::string, std::string>& keyValueMap) {
	size_t pos = 0;
	size_t len = json.length();
	while (pos < len) {
		size_t startKey = json.find('"', pos);
		if (startKey == std::string::npos)
			break;
		size_t endKey = json.find('"', startKey + 1);
		if (endKey == std::string::npos)
			break;
		std::string key = trim(json.substr(startKey + 1, endKey - startKey - 1));

		size_t startValue = json.find(':', endKey);
		if (startValue == std::string::npos)
			break;
		size_t endValue = json.find_first_of("{[\",}", startValue);
		if (endValue == std::string::npos)
			break;
		std::string value = trim(json.substr(startValue + 1, endValue - startValue - 1));

		keyValueMap[key] = value;

		pos = endValue;
	}
}
#endif

// third attempt
// handling { "key1": "value1", "key2": 100, "key3": { "key4": "value4", "key5": 105 } }
// it will be saved inside a hashmap as key1, key2, key3.key4, key3.key5

void parseJson(const std::string input) {

	istringstream iss(input);
	map<string, string> jsonMap;
	string key, value;
	string old_key; // - to save the key in nested scenario
	bool inKey = false;
	bool inValue = false;
	string result_str = "";

	key = ""; value = "";

	for (char c; iss.get(c); ) {

		{
		//	cout << "Char: " << c << " inKey: " << inKey << " inVal: " << inValue << endl;
		}
		if (c == '{') {
			//cout << "json start:" << key << ":" << endl;
			if (key.empty()) {
				// do nothing
				//cout << "key is empty" << endl;
			}
			else {
				//cout << "Key is not empty" << endl;
				old_key = key; // when we see a comma, assign old_key to key
				key += ".";
				inValue = false;
				//cout << "Debug: " <<  key << endl;
			}
			inKey = true;
		} else if (c == '"') {
			if (inKey) {
				//inKey = false;
			}
			else if (inValue) {
				//inValue = false;
				//jsonMap[key] = value;
			}
			else {
				//inKey = true;
			}
		}
		else if (c == ':') {
			inKey = false;
			inValue = true;
		}
		else if (c == ',') {
			inValue = false;
			if (!key.empty() && !value.empty()) {
				jsonMap[key] = value;
			}
			key = ""; value = "";
			//cout << "Key and val changed to empty when i saw ," << endl;
			inKey = true;
			if (old_key.empty()) {
			}
			else {
				key = old_key;
				key += ".";
			}
		}
		else if (c == '}') {
			//cout << "json end" << endl;
			inValue = false;
			jsonMap[key] = value;
			key = ""; value = "";
			//cout << "Key and val changed to empty when i saw closed brace" << endl;
			// from the old_key, remove last element added, example if old_key was "abc.def", we need to make it "abc"
			if (!old_key.empty()) {
				size_t lastPeriodPos = old_key.rfind('.');
				if (lastPeriodPos != std::string::npos) {
					// Remove the substring starting from the last period position
					old_key.erase(lastPeriodPos);
				}
			}
		}
		else if (c != ' ' && c != '\n' && c != '\t' && c != '\r') {
			if (inKey) {
				key.push_back(c);
			}
			else if (inValue) {
				value.push_back(c);
			}
		}
	}

	// Access JSON data
	//todo stop printing
	//log->Info(__FILENAME__, __LINE__, __func__, input);
	//log->Info(__FILENAME__, __LINE__, __func__, "Ouput of json string");

	//string printstr;
	//for (auto it = jsonMap.cbegin(); it != jsonMap.cend(); ++it)
	//{
	//	std::cout << it->first << ":" << it->second << "\n";
	//	printstr = it->first + ":" + it->second + ",";
	//	log->Info(__FILENAME__, __LINE__, __func__, printstr);
	//}

#if 1
	for (auto it = jsonMap.cbegin(); it != jsonMap.cend(); ++it)
	{
		std::cout << it->first << ":" << it->second << "\n";
	}
#else
	if (jsonMap.count(property_name)) {
		// key exists
		auto it = jsonMap.find(property_name);
		if (it != jsonMap.end()) {
			result_str = it->second;
		}
	}
#endif
}

int main() {
	std::cout << "Hello World" << std::endl;

    // Example JSON string
#if 0
	std::string jsonString = R"({ "key1": "value1", "key2" : 100, "key3" : { "key4": "value4", "key5" : 105 } })";
#endif

	std::string jsonString = R"({
    "status": "success",
    "message": "Key assigned to user.",
    "result": {
        "_id": "65e9e64e10635b5fb5c33291",
        "key": "9e2d320b-62fb-11ee-ac5a-026b10d3716b",
        "type": "pcat",
        "status": "Assigned",
        "assignedUser": "manish.mistry@verizon.com",
        "__v": 0,
        "systemDetails": {
            "type": "E",
            "serialNumber": "qwe5RR8933",
            "anydeskId": "121229500",
            "name": "DESKTOP-ABC456"
        },
        "updatedAt": "2024-03-20T19:35:56.099Z"
    }
})";

#if 0
    std::string jsonString = R"(
        {
            "key1": "value1",
            "key2": {
                "nested_key": "nested_value"
            },
            "key3": [1, 2, 3]
        }
    )";
#endif

	parseJson(jsonString);

#if 0
    // Parse JSON recursively
    std::map<std::string, std::string> keyValueMap;
    parseJson(jsonString, keyValueMap);

    // Print parsed key-value pairs
    for (const auto& pair : keyValueMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
#endif

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
