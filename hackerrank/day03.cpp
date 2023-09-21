/*
Day 3: Conditional Statements

Given an integer n, perform the following conditional actions:
- If n is odd, print Weird
- If n is even and in the inclusive range of 2 to 5, print Not Weird
- If n is even, 6 <= n <= 20 print Weird
- If n is even and > 20, print Not Weird

Input Format:
		A Single line containing a positive integer, n

Constraints: 1 <= n <= 100

Output Format: Weird or Not Weird
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/* ii & 1 = 1 means it is an odd number */
bool isOdd (int ii) {
    if (0 == ii %2) 
        return false;
    else
        return true;
}

int main(){
    int N;
    cin >> N;
    
    if (N < 1 || N > 100) {
        cout << "Not supported" << endl;
        return -1;
    }
    
    if (isOdd(N)) {
        cout << "Weird" << endl;
    } else if ((N >= 2) && (N <= 5)) {
        cout << "Not Weird" << endl;
    } else if ((N >= 6) && (N <= 20)) {
        cout << "Weird" << endl;
    } else {
        cout << "Not Weird" << endl;
    }
    return 0;
}

