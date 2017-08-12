/* Testing Standard Library vector class template */

#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec);

int main() {

  const int SIZE = 6;
  int a[ SIZE] = { 1, 2, 3, 4, 5, 6 };
  vector<int> v;

  cout << "Initial size of v is: " << v.size() <<
          "Initial capa of v is: " << v.capacity() << endl;

  v.push_back(1);
  v.push_back(3);
  v.push_back(4);

  cout << "Initial size of v is: " << v.size() <<
          "Initial capa of v is: " << v.capacity() << endl;

  cout << "Contents of array using pointer notation: " << endl;

  for (int *ptr = a; ptr != a + SIZE; ++ptr) 
    cout << *ptr << ' ';

  cout << endl;

  cout << "Contents using iterator ";
  printVector(v); 
}

void printVector(const vector<int> &vec) {

  vector<int>::const_iterator p1;

  for (p1 = vec.begin(); p1 != vec.end(); ++p1)
    cout << *p1 << ' ';

  cout << endl;
}
