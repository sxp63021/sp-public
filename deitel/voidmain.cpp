/*
  voidmain.cpp
  point1:
  This program is to say we can called void main() in C
  program, but not in C++

  point2:
  Another point noted in this program is to try to call
  another function before main()

*/ 
#include <iostream>
using namespace std;

int some_function() {
  cout << "Calling Some function \n";
  return 10;
}

int dummy = some_function();

//void main() { // this does not run, since C++ expects an int return val
                // compiler imposes this restriction
int main() {

  cout << "Calling main function \n";
}
