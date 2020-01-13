/*
Day 5: Loops

Task: Given an integer n, prin the first 10 multiples. n X i (1 <= i <= 10) each on one new line

Input: A single integer n

Constraints: 2 <= n <= 20

Output: Print 10 lines of output n x i = result

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


int main(){
    int n;
    cin >> n;
    
    for (int i=1; i <= 10; i++ ) {
        cout << n << " x " << i << " = " << (n * i) << endl;
    }
    return 0;
}

