/*
https://www.geeksforgeeks.org/maximum-product-subarray/
Maximum Product Subarray
Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-2, -3, 0, -2, -40}
Output:   80  // The subarray is {-2, -40}
*/

#include <iostream>
#include <climits>
#include <stack>
using namespace std;

// worry about edge cases later, all zeros, starts with zero, single element 0, (-3,0)
// always product of max consecutive integers is greater than 1

int max_product_consective_numer(int *array, int size) {
    
    if (size == 0) { cout << "Error case: returning" << endl; return INT_MIN;}
    stack<int> negativeints;

    int maxproduct = 1;

    if (size == 1) { return maxproduct;}
    int savemax = 0;
    int savednegative = 0;


    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";

        // if element is > 1
        if (array[i] > 0) {
            maxproduct *= array[i];

        } else if (array[i] == 0) { // if it is 0, save the value so far collected
            if (maxproduct > savemax) {
                savemax = maxproduct;
                maxproduct = 1; //tbd
            }
        } else if (array[i] < 0) { // negative number
            if (savednegative == 0) {
                savednegative = array[i];
            } else {
                int newval = array[i] * savednegative;
                savednegative = 0;
                maxproduct *= newval;
            }
            // check if there is one -ve element saved, so we will get a positive value
        }
    }
    cout << endl;
    if (savemax != 0) { 
        if (maxproduct > savemax) {
            savemax = maxproduct;
        }
    } else {
        savemax = maxproduct;
    }

    return savemax;
}

int main() {
//	int inputarray[] = {6, -3, -10, 0, 2}; // expected 180
   //int inputarray[] = {-1, -3, -10, 0, 60}; // expected 60	
    int inputarray[] = {-2, -3, 0, -2, -40}; // expected 80
    
    cout << "Size of input array: " << sizeof(inputarray)/sizeof(int) << endl;
	int retval = max_product_consective_numer(inputarray, sizeof(inputarray)/sizeof(int));

    cout << "max product of consecutive numbers: " << retval << endl;
    
	return 0;
}
