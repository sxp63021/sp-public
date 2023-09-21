#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    // your code goes here
    const char *single_digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if ( n <= 9 ) {
        cout <<  single_digits[n] << endl;
    } else {
        cout << "Greater than 9" << endl;
    }
    return 0;
}
