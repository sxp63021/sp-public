#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std;

/*
	Compilation: g++ -o out --std=c++11 -pthread filename.cpp
	Step1: write a queue and add elements and print elements from that queue
	Step2: Add a put and get method for this queue
	Step3: Add a thread for producer and consumer
			declare thread first, then start the thread
			pass arguments by reference - example ref(arg1), or else it will pass by value
	Step4: Add a small delay during producer thread
		     See that we print only 0 when we add this_thread::sleep_for(chron::milliseconds
	Step5: Make consumer wait until it sees the last element, else it needs to wait
		   

*/

/* Global Variables */
condition_variable cvc;
mutex mu;

void put(queue<int> &q, int i) {
	q.push(i);
}

int get(queue<int> &q, int &r) {
	int e = 0;
	if (!q.empty()) {
		r = q.front();
		q.pop();
	} else {
		e = -1;
	}
	return e;
}

void producer(queue<int> &q) {
	cout << "Starting Producer" << endl;
	for (int i = 0; i < 10; i++) {
        unique_lock<mutex> lck(mu);
		cout << "Putting element " << i << endl;
		put(q, i);
		lck.unlock();
		cvc.notify_one();
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void consumer(queue<int> &q) {
/* Step 5 Start */
	cout << "Starting consumer" << endl;
	int val = 0;
	while(val != 9) {
		unique_lock<mutex> lck(mu);
		cvc.wait(lck);
		if (get(q, val) == 0) {
			cout << "Consumer: " << val << endl;
		}
	}
/* Step 5 Stop */

/* Step 4
	int val;
	while (get(q, val) == 0) {
		cout << val << " ";
	}
*/
}


int main(int argc, char* argv[]) {

	queue<int> q1;	// Queue that can store integer numbers

/* Step 3 - start */
	thread tprod, tcons;
	tprod = thread(producer, ref(q1));
	tcons = thread(consumer, ref(q1));
	cout << endl;
	tprod.join();
	tcons.join();

/* Step 3 - stop */

/*
Step 1 and 2 - start
	// Add elements to the queue
	for (int i = 0; i < 10; i++) {
		//q1.push(i);
		put(q1, i);
	}

	// read and print elements from the queue
	int val;
	while (get(q1, val) == 0) {
		cout << val << " ";
	}
	cout << endl;
Step 1 and 2 - end
*/

	return 0;
}


