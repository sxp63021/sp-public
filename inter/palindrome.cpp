#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool chkPalindrome(string input) {
    int slen = input.length();
    
    for (int i = 0; i < slen/2; i++) {
        if (input[i] != input[slen-i-1]) {
            //cout << "input: " << i << " :" << input[i] << " :" << (slen - i - 1) <<  input[slen-i - 1] << endl;
            return false;
        }
    }
}

int main() {
	string s[] = {"abccba", "abcdba", "abcxdba", "ab", "zxyyxz", "racecar"};

    //cout << "Checking for: " << s[0] << endl;
    
	for (int i = 0; i < 6; i++) {
		bool condition = chkPalindrome(s[i]);
		cout << s[i] << " ";
		if (condition == true) {
			cout << " is a Palindrome" << endl;
		} else {
			cout << " is not a Palindrome" << endl;		
		}
	}

	return 0;
}

