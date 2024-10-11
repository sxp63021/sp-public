#include <iostream>
#include <thread>
#include <chrono>

void ThreadFunction() {
    while (true) {
        // Do your work here
        std::cout << "Thread is working..." << std::endl;

        // Sleep for 5 minutes
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

int main() {
    // Create the thread
    std::thread worker(ThreadFunction);

    // Wait for the thread to finish (if needed)
    worker.join();

    return 0;
}

