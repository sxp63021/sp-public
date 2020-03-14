#include <iostream>
#include <list>

using namespace std;

void print(list<int> &l) {
	list<int>::iterator outputIt;
	for(outputIt = l.begin(); outputIt != l.end(); outputIt++) {
		cout << *outputIt << " ";
	}
	cout << endl;
	return;
}

int main() {
	// your code goes here
	list<int> myList(5,0); 
	list<int>::iterator it = myList.begin();
	advance(it,2);
	*it = 10;
	
	print(myList);	
	
	list<int>::iterator insertIt = myList.begin();
	advance(insertIt, 3);
	myList.insert(insertIt, 11);

	print(myList);

    // insertIt will point to the newly inserted element
	cout << "Print list after remove the 0 after 11" << endl;
	advance(insertIt, 1);
	myList.erase(insertIt);
	print(myList);
	
	
	return 0;
}
