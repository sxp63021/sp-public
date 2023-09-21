/*
Day 18: Queues and Stacks

Task: Write the following declarations and implementations:

1. Two instance variables: one for your stack , and one for your queue
2. A void pushCharacter(char ch) method that pushes a character onto a stack.
3. A void enqueueCharacter(char ch) method that enqueues a character in the queue
   instance variable.
4. A char popCharacter() method that pops and returns the character at the top of the
   stack instance variable.
5. A char dequeueCharacter() method that dequeues and returns the first character in the
   queue instance variable.

Finding the palindrome

*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //Write your code here
    stack <char> mystack; // use list for stack
    queue <char> myqueue;

    public:
    // push characters onto the stack
    void pushCharacter(char c)
    {
        mystack.push(c);
    }
    void enqueueCharacter(char c)
    {
        myqueue.push(c);
    }
    char popCharacter()
    {
        char c = mystack.top();
        mystack.pop();
        return c;
    }
    char dequeueCharacter()
    {
        char c = myqueue.front();
        myqueue.pop();
        return c;
    }

};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}

