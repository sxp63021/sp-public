/*
Objective
Today, we're discussing data types. Check out the Tutorial tab for learning materials and an instructional video!

Task
Complete the code in the editor below. The variables
, , and

are already declared and initialized for you. You must:

    Declare 

variables: one of type int, one of type double, and one of type String.
Read
lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your
variables.
Use the
operator to perform the following operations:

    Print the sum of 

plus your int variable on a new line.
Print the sum of
plus your double variable to a scale of one decimal place on a new line.
Concatenate

        with the string you read as input and print the result on a new line. 

Note: If you are using a language that doesn't support using

for string concatenation (e.g.: C), you can just print one variable immediately following the other on the same line. The string provided in your editor must be printed first, immediately followed by the string you read as input.

Input Format

The first line contains an integer that you must sum with
.
The second line contains a double that you must sum with .
The third line contains a string that you must concatenate with

.

Output Format

Print the sum of both integers on the first line, the sum of both doubles (scaled to

decimal place) on the second line, and then the two concatenated strings on the third line.

Sample Input

12
4.0
is the best place to learn and practice coding!

Sample Output

16
8.0
HackerRank is the best place to learn and practice coding!

Explanation

When we sum the integers
and , we get the integer .
When we sum the floating-point numbers and , we get

.
When we concatenate HackerRank with is the best place to learn and practice coding!, we get HackerRank is the best place to learn and practice coding!.

You will not pass this challenge if you attempt to assign the Sample Case values to your variables instead of following the instructions above and reading input from stdin.
*/
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int i2;
    double d2;
    string s2, tmp_s;
    // Read and save an integer, double, and String to your variables.
    cin >> i2;
    cin >> d2;
    cin >> s2;
    while (cin >> tmp_s) {
        s2 += " " + tmp_s;
    }
    
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    cout << (i + i2) << endl;
    // Print the sum of the double variables on a new line.
    cout << fixed << setprecision(1) << (d + d2) << endl;
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    
    cout << s.append(s2) << endl;
    return 0;
}
