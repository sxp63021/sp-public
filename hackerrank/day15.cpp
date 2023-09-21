/*
Day 15: Linked Lists

Task: Complete the insert function so it creates a new Node(pass data as the Node
      constructor arg) and inserts it at the tail of linked list
      referenced by the head param. Return reference to the head node

Sample Input
4
2
3
4
1

Sample Output
2 3 4 1
*/

#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          //Complete this method
          Node *n = new Node(data);
          Node *h = head;
          if (h == NULL) 
          {
              // No elements yet, add first element
              h = n;
              return h;
          }
          while (h->next != NULL)
          {
              h = h->next;
          }
          h->next = n;
          return head;
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}
