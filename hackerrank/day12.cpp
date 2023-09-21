/*
Day 12: Inheritance

Person is Base Class
Student is derived class

Student has a vector of test scores
calculate() method returns average and returns grade

Sample Input
==============
Heraldo Memelli 8135627
2
100 80

Sample Output
=============
 Name: Memelli, Heraldo
 ID: 8135627
 Grade: O
*/

#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student (string f, string l, int id, vector<int>& ve) : Person (f,l, id)
        {
            testScores = ve;
        }

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        string calculate() {
            
            int totalSum = 0, avg = 0; string result;
            for (int i=0; i < testScores.size(); i++) 
                totalSum += testScores[i];
            avg = totalSum/testScores.size();
            
            if ((avg >= 90) && (avg <= 100)) {
                result = "O";
            } else if ((avg >= 80) && (avg < 90) ) {
                result = "E";
            } else if ((avg >= 70) && (avg < 80) ) {
                result = "A";
            } else if ((avg >= 55) && (avg < 70) ) {
                result = "P";
            } else if ((avg >= 40) && (avg < 55) ) {
                result = "D";
            } else if (avg < 40) {
                result = "T";
            }
                
            return result;
        }
};
int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}

