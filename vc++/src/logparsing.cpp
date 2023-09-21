// logparsing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

// option 1
// https://cplusplus.com/forum/beginner/125212/
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct PartialMatch
{
	std::string s;

	PartialMatch(const std::string& str) : s(str) {}

	bool operator()(const std::string& in)
	{
		size_t pos = in.find(s);
		return pos != std::string::npos;
	}
};

typedef std::vector<std::string> strvec_t;

int main()
{
	strvec_t v;
	v.push_back("apple");
	v.push_back("mango");
	v.push_back("tangerine");

	strvec_t s;
	s.push_back("app");
	s.push_back("aplet");

	for (strvec_t::const_iterator p = s.begin(); p != s.end(); ++p)
		std::cout << "Match(\"" << *p << "\") = " << (std::find_if(v.begin(), v.end(), PartialMatch(*p)) != v.end()) << std::endl;

	for (const auto& entry : s)
		std::cout << "Match(\"" << entry << "\") = " << (std::find_if(v.begin(), v.end(), [entry](const std::string& in) {return in.find(entry) != std::string::npos; }) != v.end()) << std::endl;
}
#endif

// option 2
// https://www.softwaretestinghelp.com/regex-in-cpp/
/*
#include <iostream>
#include <regex>
#include<string.h>
using namespace std;

int main()
{
	//string to be searched
	string mystr = "She sells_sea shells in the sea shore";

	// regex expression for pattern to be searched
	regex regexp("s[a-z_]+");

	// flag type for determining the matching behavior (in this case on string objects)
	 smatch m;

	// regex_search that searches pattern regexp in the string mystr
	regex_search(mystr, m, regexp);

	cout<<"String that matches the pattern:"<<endl;
	for (auto x : m)
		cout << x << " ";
	return 0;
}
*/

// use option 2 from above
string searchforpattern(vector<string> inpvec, string pattern) {

	regex pattern1(pattern);
	regex regexp(pattern1);
	smatch m;
	string result;

	for (int i = 0; i < (int)inpvec.size(); i++) {
		cout << "Output:" << inpvec[i] << endl;
		regex_search(inpvec[i], m, regexp);
		if (!m.empty()) {
			cout << "Match found: " << inpvec[i] << endl;
			result = inpvec[i];
			break;
		}
	}
	cout << "outside: " << result << endl;
	return result;
}

string findEmailAddress(string input) {
	// parse out the email address
	std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
	string text = input;
	string result;
	// Create an iterator for searching
	std::sregex_iterator it(text.begin(), text.end(), emailPattern);
	std::sregex_iterator end;

	// Loop through matching email addresses
	while (it != end) {
		std::smatch match = *it;
		std::cout << "Found email address: " << match.str() << std::endl;
		result = match.str();
		break; // return the first email address found
		++it;
	}

	return result;
}
// https://www.geeksforgeeks.org/cpp-string-to-vector-using-delimiter/
vector<string> split(string inpstr, string delimiter) {
	vector<string> vstr;
	//cout << inpstr << endl;
	int inpstrlen = inpstr.length();
	//cout << "Total Length of input string: " << inpstr.length() << endl;

	if (!inpstr.empty()) {
		int start = 0;
		do {
			// Find the index of occurence
			int idx = inpstr.find(delimiter, start);
			if (idx == string::npos) {
				//cout << "breaking from the loop" << endl;
				break;
			}

			// if found add the substring till that occurence in the vector
			int length = idx - start;
			//cout << "substring Length is: " << length << endl;
			vstr.push_back(inpstr.substr(start, length));
			start += (length + delimiter.size());
			//cout << "Value of start: " << start << endl;
		} while (true);
		//cout << "last part of string: " << inpstr.substr(start) << "HHH" << endl;
		if (start != inpstrlen)
			vstr.push_back(inpstr.substr(start));
	}

	return vstr;
}

/*
vector<string> split_using_strtok(string str, const char* delimiter)
{
	vector<string> v;
	char *token = strtok_s(const_cast<char*>(str.c_str()), delimiter);
	while (token != nullptr)
	{
		v.push_back(string(token));
		token = strtok_s(nullptr, delimiter);
	}

	return v;
} */

int main()
{
    std::cout << "Hello World!\n";

	// create a multi line string
	string inputstr = "a";
	std::string multilineString = R"(
    QPM is logged in as user 'abc@gmail.com'
License activation failed (LIME_SERVER_ERROR)
No valid licences found. maximum count reached. contact your license admin or https://cp.qti.qualcomm.com (qualcomm sales center) for assistance
    This is a
    multiline
    string.
)";

	cout << "Multiline String: " << multilineString << endl;

	string s;
	vector<string> res;

	/*
	string s = "GeeksforGeeks is a computer science portal";
	vector<string> res = split(s, " ");
	for (int i = 0; i < (int) res.size(); i++) {
		cout << res[i] << endl;
	} */

	// Delimiter is **
	// Approach 1 - use this for now
	/*
	s = "GeeksforGeeks**is**a**computer**science**portal** ";
	res = split(s, "**");

	for (int i = 0; i < (int) res.size(); i++) {
		cout << "Output:" << res[i] << endl;
	} */

	// iterate over res and figure out username, activated or deactivated

	/* Approach 2 - not working
	cout << "Approach 2" << endl;
	res = split_using_strtok(s, "**");

	for (int i = 0; i < (int)res.size(); i++) {
		cout << "Output2:" << res[i] << endl;
	} */

	// main part
	res = split(multilineString, "\n");
	string qpm_logged_user_line = searchforpattern(res, "QPM is logged in as nuser");
	string qpm_logged_id;
	if (!qpm_logged_user_line.empty()) {
		qpm_logged_id = findEmailAddress(qpm_logged_user_line);
	}

	if (!qpm_logged_id.empty()) {
		cout << "QPM logged in with userid: " << qpm_logged_id << endl;
	}

	return 0;

} // end of main

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
