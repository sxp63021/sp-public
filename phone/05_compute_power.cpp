/*
// Write a function to compute the integer power of an integer. In other words,
// implement a function that computes b to the p, where b is the base and p is
// the power. For example, if b (base) is 2 and p (power) is 3, the function
// should return 2 to the 3 which is 8.
//
// e.g.
//
// pow(2,3) = 8
// pow(3,2) = 9
//
// b can be equal to or greater than 0
// p can be equal to or greater than 0
// O(?)
*/

// Start Time: 7:30 P.M.

#include <bits/stdc++.h>
#define APPROACH2

using namespace std;

#ifdef APPROACH2
// Space complexity - O(1)
// Time Complexity - O(lg(n)) -> where is n is as big as p
long pow(int b, int p) {
	if (b == 0) return 0;
	if (p == 0) return 1;
	if (p == 1) return b;

	// if p > 2, divide it into 2 parts p/2, p/2
    int pmod = p%2;
	long retby2 = pow(b, p/2);
	if (pmod == 1) {
		// 1 is reminder
		return (retby2*retby2*b);
	} else {
		return (retby2*retby2);
	}
}
#endif

#ifdef APPROACH1
// Space complexity - O(1)
// Time Complexity - O(n) -> where is n is as big as p
long pow(int b, int p) {
	if (b == 0) return 0;
	if (p == 0) return 1;
	long ret = b, cnt = 1;;

	while(cnt < p) {
		ret *= b; cnt++;
	}
	return ret;
}
#endif

int main() {

	cout << INT_MAX << endl;

	cout << "2 to the power of 32: " << pow(2, 32) << endl;

	cout << "Size of long: " << sizeof(long) << endl;
	cout << "Size of long long: " << sizeof(long long) << endl;


	return 0;
}
