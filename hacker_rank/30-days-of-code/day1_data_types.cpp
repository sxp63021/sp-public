
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

	int i = 4;
	double d = 4.0;
	string s = "HackerRank ";

	// Declare second integer, double, and string variables
	int my_i;
	double my_d;
	string my_s, tmp_s;
	char c;

	// Read and save an integer, double, and String to your variables
	cin >> my_i; cin >> my_d; 

	// see if there are any other strings to be read
 	// string is space delimted, read until end of line
	cin >> my_s;

        do {
		cin.get(c);	

		if ('\n' == c) {
			break;
		} else {
			my_s += c;
		}

	} while (cin.peek());

	// cout sum of integers
	cout << i + my_i << endl;

	// cout sum of doubles
	cout << fixed << setprecision (1) << d + my_d << endl;

	// concatenate the strings and print them
	cout << s.append(my_s) << endl;

	return 0;
}
