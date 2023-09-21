/*
Day 16: Exceptions string to integer

Task: Read the input string see if you can convert it to an integer
      else print "Bad String"
compile: g++ day16.cpp --std=c++11
*/

#include <iostream>
#include <string>
//#include <exception>

using namespace std;


int main(){
    string S;
    cin >> S;
    try 
    {
        int inputVal = stoi(S);
        cout << inputVal << endl;
    }
    catch (...)
    {
        cout << "Bad String" << endl;
    }

    return 0;
}
