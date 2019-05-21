/*
Day 06: Review
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void parse_string(string ss) {
    
    // print even index followed by space and then odd index
    for (int i = 0; i < ss.size(); i++) {
        if (0 == i % 2) cout << ss[i];
    }
    cout << " ";
    for (int i = 0; i < ss.size(); i++) {
        if (1 == i % 2) cout << ss[i];
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num_test_cases;
    string s1;
    
    cin >> num_test_cases;
    
    if (num_test_cases < 0 || num_test_cases > 10 ) {
        cout << "Error, test case numbers are out of range" << endl;
        return -1;
    }
    
    for (int i = 0; i < num_test_cases; i++) {
        cin >> s1;
        parse_string(s1);
    }
    return 0;
}

