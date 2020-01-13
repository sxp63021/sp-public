/*
Day 7: Arrays

Task: Given an Array A of N integers, print A's elements in revese order
as a single line of space sperated numbers

Input: First line contains an integer N (size of array)
       The second line contains N space seperated integers

Constrains
1 <= N <= 1000
1 <= A(i) <= 10000, A(i) is i-th integer in the Array

Output:
Elements of A in reverse order

Sample Input:
4
1 4 3 2
Sample Output:
2 3 4 1
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
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    for (int i=arr.size(); i > 0; i--) {
        cout << arr[i-1] << " ";
    }
    cout << endl;
    return 0;
}

