#include <iostream>
#include <thread>
using namespace std;

int main() {

    // A complicated problem to solve: How many threads should I create to solve the problem? How many threads can current hardware support the problem?
    // Oversubscription is BAD!

    unsigned int num_threads_supported = std::thread::hardware_concurrency();  // Indication
    std::cout << "Number of threads my computer can support: " << num_threads_supported << std::endl;
    return 0;
}