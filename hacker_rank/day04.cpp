/*
Day 4: Class Vs Instance
Find diff between Class and instance

Task: Person class, with variable age,
      constructor that takes an integer initialAge as parameter
      Constructor needs to assign age to initialAge (if it is not negative or 0)
      2 instace methods yearPasses() and amIOld()
      - yearPassess() should increase age instance variable by 1
      - amIOld() should perform the following
        + age < 13 - "You are yound"
        + 13 <= age < 18 - "You are a teenager"
        + otherwise - "You are old"

Input Format:
First line - numer of test cases
each line contain an integer denoting age of a person

Constrains:
1 <= T <= 4
-5 <= age <= 30
*/

using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if (initialAge < 0 || initialAge > 30) {
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        } else {
            age = initialAge;
        }
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if (age < 13) {
            cout << "You are young." << endl;
        } else if (age >= 13 && age < 18) {
            cout << "You are a teenager." << endl;
        } else {
            cout << "You are old." << endl;
        }
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age++;
    }
int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}
