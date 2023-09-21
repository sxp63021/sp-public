/*
Day 14: Scope
A class constructor takes an array of integers as a parameter and saves
it to the elements instance variable
- A computeDifference() that finds the max absolute diff between any 2
  numbers in N and stores it in the maxDifference instance variable

Output: max absolute diff

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    Difference(vector<int> e)
    {
        elements = e;
    }
    void computeDifference(void)
    {
        int vecSize = elements.size();
        int maxDiff = 0;
        int diff;

        for (int i = 0; i < (vecSize - 1); i++)
        {
            for (int j = i+1; j < vecSize; j++)
            {
               diff = abs(elements[i] - elements[j]);
               if (diff > maxDiff)
               {
                   maxDiff = diff;
               }
            }
        }
        maximumDifference = maxDiff;
    }
	// Add your code here

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
