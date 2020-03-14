/*

Program to print all substrings of a given string
Given a string as an input. We need to write a program that will print all 
non-empty substrings of that given string.

Examples :

Input :  abcd
Output :  a 
          b
          c
          d
          ab
          bc
          cd
          abc
          bcd
          abcd
*/
#include <iostream>

using namespace std;

/*
Logic:
	substrings can be grom size 1 to size of string
    string of size 1, size 2, size 3, ...

*/
void substring(string s) {
	int slen = s.length();

	// first determine the size of substring you are trying to get
	for (int substringlength = 1; substringlength <= slen; substringlength++) {

		cout << "Printing strings of size: " << substringlength << endl;
		// second - determine where in the string you will start from
		for (int sposition = 0; sposition < (slen - substringlength + 1); sposition++) {
			int len = 0;
			int i = sposition;
			string substring = "";
			while (len < substringlength) {
				substring += s[i]; len++; i++;
			}
			cout << substring << endl;
		}	
	}
}

int main() {

	string s = "abcd";

	substring(s);

	return 0;
}
