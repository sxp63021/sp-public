/*
Day 10: Binary Numbers

Given a base 10 integer, convert it to binary (base 2) find
maximum consecutive 1's in n's binary representation

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
#include <unordered_map>

using namespace std;

unsigned int maxConsecutiveOnes(int val) {
    unsigned int count = 0;
    
    while (val) {
        // zero out the right most set bit of these group of patterns
        // see how many iterations are needed to zero out the whole number
        val = val & (val << 1);
        count++;
    }
    
    return count;
}

int main(){
    int n;
    cin >> n;
    
    cout << maxConsecutiveOnes(n) << endl;
    
    return 0;
}

