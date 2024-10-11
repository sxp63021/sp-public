#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>

std::string getCurrentTime() {
    // Get the current time
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert to local time
    std::tm* localTime = std::localtime(&currentTime);

    // Format the time
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

void ThreadFunction() {
    while (true) {
        // Get the current timestamp
        std::string timestamp = getCurrentTime();

        // Print the message with the timestamp
        std::cout << "[" << timestamp << "] Thread is working..." << std::endl;

        // Sleep for 5 minutes
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main() {
    // Create the thread
    std::thread worker(ThreadFunction);

    // Wait for the thread to finish (if needed)
    worker.join();

    return 0;
}

