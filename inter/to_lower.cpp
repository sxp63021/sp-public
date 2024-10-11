/*
 * Convert the input string into lower case
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	vector<string> validWeekdays = {"monday", "tuesday", "wednesday"};
	string input;

	cout << "Enter a string: ";
	getline(cin, input);

	//Print the output
	cout << "Entered string is: " << input << endl;

	transform(input.begin(), input.end(), input.begin(),
				[](unsigned char c){return tolower(c); 	});

	cout << "After transformation string is: " << input << endl;

	auto it = std::find(validWeekdays.begin(), validWeekdays.end(), input);
	if (it != validWeekdays.end()) {
		cout << "Found a match" << endl;
	} else {
		cout << "Did not find a match" << endl;
	}

	return 0;

}
