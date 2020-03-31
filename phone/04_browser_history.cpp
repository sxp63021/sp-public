/*
Store a browsed history
constraints
a. Print the browser history in chronological order
b. Print only once

Design:
 As we see a new url, add it to the stack
 When printing the browsing history, print the element if it is not there in set s1
  if the element is printed, put it in set s1
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {

	public:
		void addUrl(string url) {
			cout << "adding: " << url << endl;
			stack1.push(url);
		}
		
		void printUrl() {
			unordered_set<string> set1;
			while (!stack1.empty()) {
				string s = stack1.top();
				if (set1.find(s) == set1.end()) {
					cout << s << endl;
					set1.insert(s);
				}
				stack1.pop();
			}
		}
	private:
		stack<string> stack1;

};

int main() {

	string hist1[] = {"bloomberg.com", "google.com", "bbc.co.uk"};
	string hist2[] = {"bloomberg.com", "bbc.co.uk", "cnn.com", "bbc.co.uk"};

	Solution s1, s2;

	for(int i = 2; i >= 0; i--) {
		s1.addUrl(hist1[i]);	
	}
	cout << "Printing History 1 " << endl;
	s1.printUrl();


	for(int i = 3; i >= 0; i--) {
		s2.addUrl(hist2[i]);	
	}
	cout << "Printing History 2 " << endl;
	s2.printUrl();

}
