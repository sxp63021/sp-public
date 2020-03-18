/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.

*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

    int myAtoi(string str) {
        
        // delete any non white characters
        // first character after non-white can be + or - or a digiti, else return 0
        // if starting with digit, assume it is a positive number
        // aggregate into a long, since we are looking for numb between 2**-31 and 2**+31
        
        unsigned int uiretval=0;
        // if the last bit in iretval is changing to 1, it is not acceptable, i.e going over 31 bits
        int sign = 1;
       	cout << "In fn: str: " << str << " strlen: " << str.length() << endl; 
        if (str.length() == 0) return 0;
        int pos = 0;
        // move pos to read first non space char
        while(str[pos] == ' ') { pos++; }
        if (pos == (str.length())) return 0;
		cout << "Starting at position: " << pos << endl;
        // check what is the first non-space char
        if (str[pos] == '-'){ sign = -1; pos++;}
        else if (str[pos] == '+') { sign = 1; pos++;}
        else if (isalpha(str[pos])) return 0;
        
        while((pos <= str.length()-1) && isdigit(str[pos])) {
			cout << "Digit: " << str[pos] << endl;
			cout << "Value collected so far: " << uiretval << endl;
			if (uiretval > (INT_MAX - (str[pos]-48))/10) { if (sign < 1) return INT_MIN; else return INT_MAX; }
            uiretval = uiretval*10 + (unsigned int) (str[pos] - 48);
            if (int(uiretval) < 0) { cout << "checking int val of uint + digit" << endl; return INT_MIN; }
            pos++;
        }

        return (sign*uiretval);
    }

int main() {

	string s1 = "1";
//	string s1 = "42";
//	string s1 = "-91283472332";
	cout << "Original string: " << s1 << " converted to int: " << myAtoi(s1) << endl;
	return 0;

}
