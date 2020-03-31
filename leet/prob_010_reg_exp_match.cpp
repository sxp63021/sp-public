#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        // one check is to make sure s has only a-z
        // check if p is a-z or "." or "*"
        
        unordered_set<char> setpattern; setpattern.insert('.');
        setpattern.insert('*');
        
        if ( (s.length() == 0) && (p.length() == 0) ) return true;
        if (s.length() == 0) return false;
        if (p.length() == 0) return false;
        
        // * means, the before char can be there 0 or more number of times
        // . means, 1 character
        // .* means, any characters can be present any number of times
        
        // stack1 -> elements of s
        // stack2 -> elements of p
        stack<char> sp;
        int slen = s.length(), plen = p.length();
        int sptr = 0;
        
        // can start with a-z or .
        if (p[0] == '*') return false;
        
        for(int i = 0; i < plen; i++) {
			cout << "Iteration: " << i << " p[i]: " << p[i]  << endl;
            if (p[i] == '.') {
                //peek i+1 to see if it is *
                int move = 0;
                if ( ((i+1) <= (plen-1)) && (p[i+1] == '*')) {
                    // move pointer (sptr) to the last element+1 of s
                    //sptr = slen; // cannot move anything further
                    move=INT_MAX;
                    i++;
                } else { // base case + adding just the period to detect one character
                    // move sptr by one
                    move = 1;
                } 
                // act on move
                if (sptr == slen) { // check if it is beyond last chat
                    //cannot move anything else // return false
                    return false;
                }
                if (move == 1) {
                    sptr += 1;
                } else if (move == INT_MAX) {
                    sptr = slen;
					cout << "Moving sptr to max position sptr: " << sptr << endl;
                }
            } else if ((int(p[i]) <= 122) || (int(p[i]) >= 97) ) { // is an ascii char between a-z
                // look at the next char
                if (((i+1) <= (plen-1)) && (p[i+1] == '*')) {
                    // need to account for 0 to multiple characters of p[i]
                    int stop = 1;
                    int cnt = 0;
					int imove = 0;
                    do {
                        // case if there is a match more than 0
                        if (s[sptr] == p[i]) {
                            sptr++;
                            cnt++;
                        } else {
                            stop = 0;
							if (cnt == 0) {	// no elements in s and p are matching
								// nothing to do
								imove = 1;
							} else {
								// check in pattern p, if p[i] is matching
								int tmpptr = i+2;
								int tmpcnt = 0;
								while (tmpptr <= plen-1) {
									if (p[i] == p[tmpptr]) {
										tmpcnt++;
										tmpptr++;
									} else {
										break;
									}
								}
								
								if (tmpcnt == 0) {	// p[i]* is taken care of imove=1
									imove = 1;
								} else if (tmpcnt <= cnt) {
									imove = tmpcnt + 1;
								} else {
									// far too many characters of p[i] than needed
									return false;
								}
							}
                        }
                    } while (stop == 1);
                    i += imove; // move i
                    
                } else { // this is base case
                    // move sptr to next element
                    if (p[i] == s[sptr]) { // matches - so move the sptr
                        sptr++;
                    } else { // does not match
						cout << "Returning here" << endl;
                        return false;
                    }
                }
            }
        }
        
        // once out of for loop, sptr should be on the last element or else not right
		cout << "s len: " << slen << " sptr: " << sptr << endl;
        if (sptr == slen) {
			return true;
		} else {
			return false;
		}
    }
};

int main() {
	Solution sol1;

//	string s1 = "ab"; // ab, aa, mississippi
//	string p1 = ".*"; // .*, a , mis*is*ip*.
	string s1[] = {"ab", "aa", "mississippi", "aaa", "aab", "aaa"};
	string p1[] = {".*", "a" , "mis*is*ip*.", "a*a", "c*a*b", "ab*a*c*a"};
	int cnt = 6;

	for(int i = 0; i < cnt; i++) {
		cout << "Matching s1: " << s1[i] << " with pattern: " << p1[i] << " result: " << sol1.isMatch(s1[i], p1[i]) << endl;
	}

	return 0;
}
