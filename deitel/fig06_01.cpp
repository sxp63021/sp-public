
// Fig 6.1: fig 06_01.cpp
// Create a structure, set its members, and print it.

#include <iostream>
#include <iomanip>

using namespace std;

struct Time {	// structure definition
  int hour; // 0 - 23
  int min;  // 0 - 59
  int sec;  // 0 - 59
};

void printMilitary( const Time & ); // prototype
void printStandard( const Time & ); // prototype

int main() {

  Time dinnerTime; 	// variable of new type Time

  // set members to valid values
  dinnerTime.hour = 18;
  dinnerTime.min  = 30;
  dinnerTime.sec  = 00;

  cout << "Dinner will be held at ";
  printMilitary( dinnerTime );
  cout << " military time,\nwhich is ";
  printStandard( dinnerTime );
  cout << " standard time.\n";

  // set members to invalid values
  dinnerTime.hour = 29;
  dinnerTime.min  = 73;

  cout << "\nTime with invalid values: ";
  printMilitary( dinnerTime );
  cout << endl;
 
  // skipping return 0, let me see what happens
}

// Print the time in military format
void printMilitary( const Time &tt ) {

  cout << setfill('0') << setw(2) << tt.hour << ":"
       << setfill('0') << setw(2) << tt.min;

  // If iomanip is not allowed
  // cout << (tt.hour < 10 ? "0" : "") << tt.hour << ":"
  // cout << (tt.min < 10 ? "0" : "") << tt.min;

}


// Print the time in standard format

void printStandard( const Time &t ) {

  cout << ( (t.hour == 0 || t.hour == 12) ?
            12 : t.hour % 12 )
       << ":" << (t.min < 10 ? "0" : "") << t.min
       << ":" << (t.sec < 10 ? "0" : "") << t.sec
       << (t.hour < 12 ? " AM" : " PM");

}
