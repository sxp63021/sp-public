// fig 5.6
// Cube a variable using call-by-value
#include <iostream>
using namespace std;

int cubeByValue( int ); // prototype

int main()
{
	int number = 5;
	
	cout << "The original value of number is " << number << endl;
	number = cubeByValue( number );
	cout << "\nThe new value of number is " << number << endl;
	return 0;
}

int cubeByValue(int n)
{
	return n * n * n;	// cube local variable n
}

