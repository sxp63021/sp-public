
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ss Solution {
public:
    
    // find the size of vector
    // check the first alphabet in first element and
    // verify if it is same in other strings
    // keep iterating over the length of this string
    // if any of the strings in vector is not matching,
    // time to exit
    string longestCommonPrefix(vector<string>& strs) {
        
        int strslen = strs.size();
        
        string output = "";
        int indx = 0;
        if (0 == strslen) return output;
        if (1 == strslen) return strs[0];
        
        // base everything on first string
        int firststrlen = strs[0].length();
        while (indx < firststrlen) {
            char tochkchar = strs[0][indx];
            for(int i = 1; i < strslen; i++) {
                // check if length of string is bigger than indx
                if (indx < strs[i].length()) {
                    // continue
                } else {
                    return output;
                }
                if (tochkchar != strs[i][indx]) {
                    //cout << strs[i] << " " << strs[i][indx] << endl;
                    return output;
                }   
            
                if (i == (strslen-1)) {
                    // last element
                    // copy this character into output
                    output += strs[0][indx];
                    indx++;
                }    
            }
        }
        return output;
    }
};

int main() {

	Solution s1;

//	vector<string> v1 = {"flower", "flow", "flight"};
	vector<string> v1 = {};

	cout << s1.longestCommonPrefix(v1) << endl;

	return 0;
}
