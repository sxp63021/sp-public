/*
Filename: Exp.h
Description: Define expression class here
*/

#include <string>
#include <stack>

class Node;

class Exp {

  private:
   std::stack <char> exprStack;
   std::stack <Node *> nodeStack;

  void processOperator(char inputOp);
  void buildTree(char cc);
  int prioComp (char op);

  public:
    Node *handle(std::string& inputStr);

};
