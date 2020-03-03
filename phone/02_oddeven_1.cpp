/*
	Have two threads and print odd and even
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mu;
condition_variable
cv;
bool odd = false;
bool even = false;

void myprint(int val) {
	cout << val << " ";
}

void eventhread(int maxval) {
	int i = 2;
	if (maxval == 0) { return; }
	while(i <= maxval) {
		unique_lock<mutex> lck(mu);
		cv.wait(lck, []() {return even;});
		myprint(i);
		lck.unlock();
		cv.notify_one(); odd = true; even = false;
		i += 2;
	}
}

void oddthread(int maxval) {
	int i = 1;
	if (maxval == 0) { return; }
	while(i <= maxval) {
		unique_lock<mutex> lck(mu);
		cv.wait(lck, []() {return odd;});
		myprint(i);
		lck.unlock();
		cv.notify_one(); even = true; odd = false;
		i += 2;
	}
}

int main() {

	thread teven, todd;

	todd  = thread(oddthread, 10);
	odd = true;
	teven = thread(eventhread, 10);

	todd.join();
	teven.join();
	cout << endl;
}
