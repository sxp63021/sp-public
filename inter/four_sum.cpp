/*
Given an array of integers arr and a number s, write a function fourSum() that finds index of those numbers in arr that sum up to s.
Your function should return an array of index of these numbers in an ascending order.

Input: 
	arr = [2, 7, 4, 0, 9, 5, 1, 3]
	s = 20
	
Output: 
	[1, 2, 3, 4]

Explanation: 
	arr[1] + arr[2] + arr[3] + arr[4] = 7 + 4 + 0 + 9 = 20

compile: g++ -std=c++11 four_sum.cpp

Assumption1: The order of elements in input array cannot be changed
-OR-
Assumption2: Can pick any elements from the input array, need not be contiguous
             every element only appears once
-OR-
Assumption3: Can pick any elements from the input array, need not be contiguous
             every element only appears once
*/

#include <iostream>
#include <vector>
#include <set>
#define ASSUMPTION2

using namespace std;

#ifdef ASSUMPTION2
/* will return empty vector if indexes are not found */
/* Logic, save elements in a set, so auto sorted. (value, index)
   write your own compare() function
   All the values are in increasing order
   findSum(set, sum, numofdigits) - recursive fn
*/
  
bool findSum(set<pair<int,int>, compare> &s, int sum, int digits, vector<int> &v) {

	set<pair<int,int>>::iterator it;
	it = s.lower_bound(make_pair(sum, 1));
	
	if ((digits == 1) && (it == s.end())) {
		return false;
	}
	// check if the element at iterator is equal to sum
	if (digits == 1) {
		if ((*it).first == sum) {
			v.push_back((*it).second);
		}
		return true;
	} else {	//
		sum -= (*it).first;
		digits -= 1;
		v.push_back((*it).second);
		s.erase(it);
		return findSum(s, sum, digits, v);
	}

}
 
struct compare {
    bool operator()(const pair<int,int> &lhs,
                    const pair<int,int> &rhs) const {
        return lhs.first < rhs.first;
    }
};

void fourSum(vector<int> &v, const int sum) {

	set<pair<int,int>, compare> s;
	int vsz = v.size();
	for (int i = 0; i < vsz; i++) {
		s.insert(make_pair(v[i], i));
	}

	vector<int> voutput;
	if (findSum(s, sum, 4, voutput) == true) {
		for(auto i: voutput) {
			cout << i << " ";
		}
		cout << endl;
	} else {
		cout << "Did not find matching indexes" << endl;
	}
	//return v;
	
}
#endif

#ifdef ASSUMPTION1
int fourSum(vector<int> &v, const int sum) {

	int startindex = -1;
	int sindex = 0;
	int vsize = v.size();
	int v4sum = 0;

	if (vsize < 4) {
		return -1;
	}

	v4sum = v[0]+v[1]+v[2]+v[3];

	for (int i = 0; i < (vsize - 1 - 4); i++) {
		if (v4sum == sum) {
			startindex = i;
			break;
		} else {
			v4sum -= v[i];
			v4sum += v[i+4];
		}
	}

	return startindex;
}
#endif

int main() {

	int sum = 18;
	vector<int> vint {2,7,4,0,9,5,1,3};

	for (auto i : vint) {
		cout << i << " " ;
	}
	cout << endl;

#ifdef ASSUMPTION2
// this function will print the indexes as well
	fourSum(vint, sum);
#endif

#ifdef ASSUMPTION1
	int startindex = fourSum(vint, sum);

	if (startindex >= 0) {
		cout << "Found 4 consecutive elements that add up to " << sum << " ->";
		for(int i = 0; i < 4; i++) {
			cout << (i+startindex) << " ";
		}
	} else {
		cout << "Did not find 4 consecutive elements that add up to " << sum;
	}
	cout << endl;
#endif

	return 0;

}
