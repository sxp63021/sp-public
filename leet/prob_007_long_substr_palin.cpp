#include <iostream>
#include <string>
#include <list>

using namespace std;

    // check if the string is a palindrome?
    bool isPalindrome(string s) {
		if (s.length() == 1) return true;
        int rindex = s.length() - 1, lindex = 0;
        while (rindex > lindex) {
            if (s[lindex++] != s[rindex--]) return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        // algorithm
        // find all possible substrings, check if the substring is palindrome
        // save length of palindrome as you check, return the largest 
        
        int slen = s.length();
        //     ABABCDEFG
        //     ^  
        // startpos
        //     ABABCDEFG
        //     ---
        //     ^ substrlen
        int maxsubstrlen = 0; string maxsubstr = "";
        
        for (int startpos = 0; startpos <= (slen - 1); startpos++) {
            for (int substrlen = 1; substrlen <= (slen - startpos); substrlen++ ) {
                string ss = s.substr(startpos, substrlen);
				if ((isPalindrome(ss)) && (ss.length() > maxsubstrlen)) {
					maxsubstrlen = ss.length(); maxsubstr = ss;
				}
            }
        }

		return maxsubstr;
    }

int main() {

	
//	string s1 = "racecar";
	string s1 = "a";
	string ret = longestPalindrome(s1);

	if (ret.length() != 0) {
		cout << "Input: " << s1 << " longest palindrome: " << ret << endl;
	}

	return 0;
}
