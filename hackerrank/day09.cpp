/*
Day 9: Recursion 3

Task: Write a factorial function that takes a positive integer N, prints
      the result of N!

2 <= N <= 12

Output: value of N!
*/

#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    // Complete this function
    if (1 == n) {
        return 1;
    } else {
        return (n * factorial(n-1));
    }
}

int main() {
    int n;
    cin >> n;
    int result = factorial(n);
    cout << result << endl;
    return 0;
}

