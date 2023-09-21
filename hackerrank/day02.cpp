/*

Day 2: Operators

Objective
In this challenge, you'll work with arithmetic operators. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost.

Note: Be sure to use precise values for your calculations, or you may end up with an incorrectly rounded result!

Input Format

There are
lines of numeric input:
The first line has a double, (the cost of the meal before tax and tip).
The second line has an integer, (the percentage of being added as tip).
The third line has an integer, (the percentage of

being added as tax).

Output Format

Print the total meal cost, where
is the rounded integer result of the entire bill (

with added tax and tip).

Sample Input

12.00
20
8

Sample Output

15

Explanation

Given:
, , Calculations:



We round to the nearest dollar (integer) and then print our result, .
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    float my_meal, my_tip, my_tax;
    cin >> my_meal;
    cin >> my_tip;
    cin >> my_tax;
    
    //cout << fixed << setprecision(0);
    cout << "The total meal cost is " << fixed << setprecision(0) << my_meal * (1 + (my_tip+my_tax)/100) << " dollars." << endl;
    return 0;
}
