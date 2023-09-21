#include "Node.h"

using namespace std;

int Node::evaluate()
{
  switch(_operator) {
    case '#': return _value;
              break;
    case '*': return _left->evaluate() * _right->evaluate();
              break;
    case '+': return _left->evaluate() + _right->evaluate();
              break;
    case '-': return _left->evaluate() - _right->evaluate();
              break;
  }
  return -1;
}

void Node::print()
{
  cout << "printing Node element " << endl;

  cout << "op: " << _operator;
  cout << "val: " << _value;
  cout << endl;

  if (_left != NULL) {
    _left->print();
  }

  if (_right != NULL) {
    _right->print();
  }
}
