#include <iostream>
#include <thread>

int main() {
    
    std::thread t([] {
        int numthreads = std::thread::hardware_concurrency();
        std::cout << "Number of threads=" << numthreads << std::endl;
    });
    
    t.join();

    return 0;
}