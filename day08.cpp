/*
Day 08: Dictionaries and Maps

Task: Given n names and phone numbers, map names to phone numbers
      Query a name to find their number
      Use Dictionary/HashMap DS

Input: The first line contains an integer n, denoting the number of
       entries in the phone books
       each line after this has 2 space separated values on single line
       "friends name" "8 digit phone number"

Output: On a new line for each query print "Not found" or "name=12345678"

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string fname;
    int phnum, count;
    map<string, int> dir;
    map<string, int>::const_iterator it;
    
    cin >> count; // number of records being input
    
    for (int i = 0; i < count; i++) {
        cin >> fname;
        cin >> phnum;
        dir.insert(pair<string,int>(fname, phnum)); 
    }
    
    while (cin >> fname) {
        if ((it = dir.find(fname)) != dir.end()) {
            cout << fname << "=" << it->second << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    
    return 0;
}
