/*
struct Node
{
char _operator;
int _value;
Node* _left;
Node* _right;
double evaluate()
{
switch(_operator)
{
case '#': return _value;
case '*': return _left->evaluate() * _right->evaluate();
case '+': return _left->evaluate() + _right->evaluate();
}
return -1;
}
};

expression: 5 - 4 + 2 * 3

First - we need to parse the expression and put expression in a binary tree
        then we can traverse the binary tree and solve the equation.

Second - looking at the Node class, looks lik we can call root->evaluate
         and this should recursively call all the nodes and compute

*/

#include <iostream>
#include "Node.h"
#include "Exp.h"

using namespace std;

int main()
{
  string inputStr;
  Exp ee; 

  cout << " Enter equation to solve: ";
  getline (cin, inputStr);

  if (inputStr == "")
  {
    cout << "Empty string entered, exiting" << endl;
    return 0;
  }

  Node *rt = ee.handle(inputStr);

//  rt->print(); // check if the equation is stored correctly

  cout << "Solution of " << inputStr << " is: " << rt->evaluate() << endl;

}
