/*
take an input string
reverse the string
Step 1:
original -> "Test, is running today!"
return   -> "today! running is Test,"
Step 2:
Leave the punctuation marks in their own place
original -> "Test, is running today!"
return   -> "today, running is Test!"
Compilation: g++ -std=c++14 string_reverse.cpp
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // swap

using namespace std;

/*
Algo - use a istringstream, use the default space(" ") delimiter
       read the string and attach the words
*/
void reverseStr(string inputstr) {
	istringstream is(inputstr);
	cout << "Step1: original string: " << inputstr << endl;
	string eachword;
	string retval = "";
	while (is >> eachword) {
		cout << eachword << "-" << endl;
		if (retval.length() == 0) {
			retval = eachword;
		} else {
			retval = eachword + " " + retval;
		}
	}

	cout << retval << endl;
}

/*
Algo - use istringstream, use space as default delimiter
       read string from front and back
       add string to vector
       swap the strings front and back, until we reach the middle
       while swapping, retain the punctuation location
*/
void mysplit(string a, string &astarts, string &amiddles, string &aends) {
	int astart=-1, astop = -1;
	// check for punctuation at beginning of string
	string s = a; int i = 0;
	int slen = s.size();
//	while(s.at[i] < 'a' || s.at[i] > 'Z') { i++; }
	while(!isalpha(s[i])) { i++; }
	if (i > 0) { astart = i;} // else astart = -1;
	// check for punctuation at beginning of string
	i = slen - 1;
//	while(s.at[i] < 'a' || s.at[i] > 'Z') { i--; }
	while(!isalpha(s[i])) { i--; }
	if (i < (slen -1)) { astop = i;} // else astop = -1;
//	cout << "astop: " << astop << " for string: " << a << endl;
	if (astart >= 0) { astarts = a.substr(0, (astart - 0)); } else { astarts = ""; }
	if (astop > 0) { aends = a.substr(astop+1, (slen - 1 - astop)); } else { aends = "";}
	if (astart == -1) astart = 0;
	if (astop == -1) astop = (slen - 1);
//	cout << "astart: " << astart << " astop: " << astop << endl;
	amiddles = a.substr(astart, (astop - astart + 1));
	//cout << "astart: " << astarts << endl;
	//cout << "amiddle: " << amiddles << endl;
	//cout << "aend: " << aends << endl;
}

void myswap(string &a, string &b) {
	// parse through string, find start position of punctuation
	// end of punctuation
	int slen, i;
	string s;
	string astarts, amiddles, aends;
	string bstarts, bmiddles, bends;
	//cout << "a: " << a << " b:" << b << endl;
	mysplit(a, astarts, amiddles, aends);
	mysplit(b, bstarts, bmiddles, bends);

	a = astarts + bmiddles + aends;
	b = bstarts + amiddles + bends;
}

void reverseStr1(string inputstr) {
	istringstream is(inputstr);
	cout << "Step2: original string: " << inputstr << endl;
	string eachword;
	string retval = "";
	vector<string> vs;
	while (is >> eachword) {
		//cout << eachword << "-" << endl;
		vs.push_back(eachword);
	}
	int vssize = vs.size();
	for (int i = 0; i < vssize/2; i++) {
		// swap i-th element and (vssize - 1 - i) the element
		// standard swap gives normal swaps, if you want a diff behaviour
		// see next comment
		//swap(vs[i], vs[vssize - 1 - i]);
		// customized swap to retain the punctuation spaces
		myswap(vs[i], vs[vssize - 1 -i]);
	}

	for (auto e : vs) { cout << e << " "; }
	cout << endl;
	
	
}

int main() {
	
	reverseStr("Testing, is  being done!");
	reverseStr1("Testing1, is1 being1 done1!");

	return 0;
}

