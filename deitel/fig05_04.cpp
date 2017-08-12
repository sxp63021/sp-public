
#include <iostream>
using namespace std;

int main()
{
	int a;	// a is an integer
	int *aPtr;	// aPtr is a pointer to a variable of type int

	a = 7;
	aPtr = &a; //aPtr set to address of integer a

	cout << "The address of a is : " << &a
	     << "\nThe value of aPtr is " << aPtr;

	cout << "\n\nThe value of a is " << a
	     << "\nThe value of *aPtr is " << *aPtr;

	cout << "\nAddress of *aPtr " << &aPtr << endl;

	cout << "\n\nShowing that * and & are inverses of "
	     << "each other.\n&*aPtr = " << &*aPtr
	     << "\n*&aPtr = " << *&aPtr << endl;

	cout << "Size of a " << sizeof(a)
	     << "Size of aPtr " << sizeof(aPtr) << endl;

	return 0;
}
