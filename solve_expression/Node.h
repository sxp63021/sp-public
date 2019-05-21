/*
Name: Node.h
Description: using the struct defintion given in the problem statement
             Enhancing or modifying that struct to suit the algo
*/

#include <iostream>
using namespace std;

class Node
{
  public:
    char   _operator;
    int    _value;
    Node*  _left;
    Node*  _right;

    Node(char symb, int val);
    Node(char symb, Node *l, Node *r);
    int evaluate(); // recursive call
    void print();
};

inline Node::Node(char symb, int val) :
                   _operator(symb), _value(val), _left(NULL), _right(NULL) {}

inline Node::Node(char symb, Node *l, Node *r) :
                 _operator(symb), _value(-1), _left(l), _right(r) {}

