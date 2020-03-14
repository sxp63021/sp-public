#include <iostream>
#include <set>
using namespace std;

struct compare {
    bool operator()(const pair<int,int> &lhs, 
                    const pair<int,int> &rhs) const {
        return lhs.first < rhs.first;
    }
};

int main() {
	// your code goes here
	multiset<pair<int,int>, compare> ms;
	std::multiset<pair<int,int>>::iterator itlow,itup;
	
	//ms.insert(pair<0,3>);
	ms.insert(make_pair(0,3));
	ms.insert(make_pair(0,4));
	ms.insert(make_pair(2,5));
	ms.insert(make_pair(2,6));
	ms.insert(make_pair(1,3));
	ms.insert(make_pair(1,4));
    ms.insert(make_pair(20,3));
    ms.insert(make_pair(20,4));
    ms.insert(make_pair(30,3));
    ms.insert(make_pair(30,4));
    ms.insert(make_pair(30,5));
    ms.insert(make_pair(30,6));
    ms.insert(make_pair(40,2));	
    
	for (auto it: ms)
    	std::cout << it.first << " " << it.second << endl;
    
    itlow = ms.lower_bound (make_pair(20,1));    
    for (std::multiset<pair<int,int>>::iterator it=itlow; it!=ms.end(); ++it)
    std::cout << ' ' << (*it).first ;
    
    std::cout << "\nSearching for 20 and print elements after 20" << std::endl;
    itlow = ms.find(make_pair(20,1));
    for (std::multiset<pair<int,int>>::iterator it=itlow; it!=ms.end(); ++it)
    std::cout << ' ' << (*it).first ;
    
    std::cout << "\nSearching for 30 and erasing 30, Print after 30, only one element removed" << std::endl;
    itlow = ms.find(make_pair(30,1));
    ms.erase(itlow);
    itlow = ms.find(make_pair(30,1));
    for (std::multiset<pair<int,int>>::iterator it=itlow; it!=ms.end(); ++it)
    std::cout << ' ' << (*it).first ;

    std::cout << "\nErasing 30, Print rest of elements, you will not see any more 30" << std::endl;
    ms.erase(make_pair(30,1));
    itlow = ms.find(make_pair(40,1));
    for (std::multiset<pair<int,int>>::iterator it=itlow; it!=ms.end(); ++it)
    std::cout << ' ' << (*it).first ;
    
	return 0;
}

