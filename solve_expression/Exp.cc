#include "Exp.h"
#include "Node.h"
#include <sstream>
#include <iostream>

using namespace std;

int Exp::prioComp (char op)
{
  switch (op) {
    case '+' : return 1;
    case '-' : return 1;
    case '*' : return 5;
  } 
  cout << "Error in prioCmp - check" << endl;
  return -1;
}

Node *Exp::handle(std::string &str)
{

  for(string::iterator token = str.begin(); token != str.end(); token++)
  {

    if ( (*token == '*') || (*token == '+') || (*token == '-') )
    {
      processOperator(*token);
    } else {
      int numb;
      numb = *token - '0';

      Node *n1 = new Node('#', numb);

      nodeStack.push(n1);
     // cout << "pusing " << numb << endl;
    } // end of if
              
  } // end of for loop

  while (!exprStack.empty()) {
    buildTree(exprStack.top());
    exprStack.pop();
  }

  cout << "num elements in nodeStack : " << nodeStack.size() << endl;

  Node *p = nodeStack.top();

  return p;

}

void Exp::processOperator(char cc)
{
  int prio = prioComp(cc);

  while ((!exprStack.empty()) && (prio <= prioComp(exprStack.top())) ) {
     buildTree(exprStack.top() );
     exprStack.pop();
  } // end of while

  exprStack.push(cc);
}

void Exp::buildTree(char cc)
{
  Node *r = nodeStack.top();
  nodeStack.pop();
  Node *l = nodeStack.top();
  nodeStack.pop();

  Node *n = new Node(exprStack.top(), l, r);

  nodeStack.push(n);
}


