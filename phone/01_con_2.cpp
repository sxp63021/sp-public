#include <iostream>
#include <thread>
#include <queue>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
    Compilation: g++ -o out filename.cpp
    Step1: write a queue and add elements and print elements from that queue
	Step2: Add a put and get method for this queue
	Step3: Add a thread for producer and consumer
		   declare thread first, then start the thread
		   pass arguments by reference - example ref(arg1), or else it will pass by value
	Step4: Add a small delay during producer thread
           See that we print only 0 when we add this_thread::sleep_for(chron::milliseconds
           Add a mutex for the queue, so prod and consumer are not stepping
	Step5: Step 4 will cause only 1 element of the q to be print
           Adding a conditional variable so consumer thread need not be in a busy loop
*/

// global variables
mutex mu, mu1;
condition_variable condc;

void put(queue<int> &q, int i) {
	mu.lock();
	q.push(i);
	mu.unlock();
}

int get(queue<int> &q, int &i) {
	int ret = 0;
	mu.lock();
	if(!q.empty()) {
		i = q.front();
		q.pop();
	} else {
		ret = -1;
	}
	mu.unlock();
	return ret;
}

void prod(queue<int> &q) {
	cout << "Starting producer thread" << endl;
	for (int i = 0; i < 10; i++) {
		put(q, i);
		this_thread::sleep_for(chrono::milliseconds(10));
		condc.notify_one();
	}
}

/* Consumer thread will exit when it sees the last element */
void cons(queue<int> &q) {
	cout << "Starting consumer thread" << endl;
	int val = 0;
/* Step 4
	while(get(q, val) != -1) {
		cout << val << " ";
	}
*/
/* Step 5 */
	while (val != 9) {
		unique_lock<mutex> lck(mu1);
		condc.wait(lck);	// it will wait on this until it gets a signal
		if (get(q,val) != -1) {
			cout << val << " ";
		}
	}
	cout << endl;
}

int main() {
	queue<int> q1;

	thread tprod, tcons;

	tprod = thread(prod, ref(q1));	// start the producer thread
	tcons = thread(cons, ref(q1));	// start the consumer thread

	tprod.join();
	tcons.join();

/*
	for (int i = 0; i < 10; i++) {
		//q1.push(i);
		put(q1, i);
	}

	int val;
	while(get(q1, val) != -1) {
		cout << val << " ";
	}
	cout << endl;
*/
/* Step 1
	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
*/

	return 0;
}

