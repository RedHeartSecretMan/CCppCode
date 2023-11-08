#include <thread>
#include <iostream>

void threadFunction() {
    // Do some work...
    std::cout << "Thread function\n";
}

int main() {
    std::thread t(threadFunction);
    // If you uncomment the next line, it will wait for the thread to finish before proceeding.
    t.join();

    std::cout << "Main function\n";
    return 0;
}
