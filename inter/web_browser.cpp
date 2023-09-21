/*
web browser application
support the following methods

a. back() -> takes you back by one page, set the currenturl to previous page
b. forward() -> takes you front by one page, set currenturl to next page
c. go(string) -> takes you to the respective page, set currenturl to this page
d. if you go back() and go(string) -> this should cause it to forget all
   pages in the front()
   so front() will not take you to any page

back() -> error
front() -> error
go("google.com") -> google.com
go("fb.com") -> fb.com
go("apple.com") -> apple.com
go("bloomberg.com") -> bloomberg.com
back() -> apple.com
back() -> fb.com
go("cnn.com") -> cnn.com (erase apple.com and bloomberg.com)
front() -> error
back() -> fb.com
*/

#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

list<string> historylist;
list<string>::iterator currenturl;

void back() {
    if (historylist.empty() || (currenturl == historylist.begin())) {
        cout << "back(): error" << endl;
        return;
    }

    currenturl = prev(currenturl);
    cout << "back(): " << *currenturl << endl;

}

void front() {

    if (historylist.empty() || (currenturl == next(historylist.end(), -1))) {
        cout << "front(): error" << endl;
        return;
    }

    advance(currenturl,1);
    cout << "front(): " << *currenturl << endl;


}
void go(string url) {

    if (historylist.empty() || (currenturl == next(historylist.end(), -1))) {
        historylist.push_back(url);
        //advance(currenturl, -1);
        currenturl = next(historylist.end(), -1);
        cout << "go: " << *currenturl << endl;
    } else {
        // erase the elements after currenturl till end of list
//      list<string>::iterator fromit = currenturl
        historylist.erase(next(currenturl,1), historylist.end());
        historylist.push_back(url);
        currenturl = next(historylist.end(), -1);
        cout << "go: " << *currenturl << endl;
    }

}

int main() {

    back();
    front();
    
    go("google.com");
    go("fb.com");
    go("apple.com");
    go("bloomberg.com");
    
    back();
    
    back();

    go("cnn.com");
    front();
    back();
    

    return 0;
}


