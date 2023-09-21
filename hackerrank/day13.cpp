/*
Day 13: Abstract Classes

Book class, Solution class, write a MyBook class  which will
- inherit from Book
- Has a parameterized constructor taking 3 params (str title, str author, int price)
- implements the Book class abstract display() method so it prints 3 lines
  1. Title:
  2. Author:
  3. Price:
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

// Write your MyBook class here
class MyBook: public Book {

    protected:
        int price;
    
    public:
    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    MyBook (string t, string a, int p) : Book (t, a) {
        price = p;
    }
    
    
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};    
// End class
int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}


