#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void printline(const char* funcID, int i) {
    m.lock();
    std::cout << funcID << "() i=" << i << std::endl;
    m.unlock();
}

void hello() {
    for (int i=0; i<50; i++) { 
        printline("hello", i); 
    }
}

int main() {
    std::thread t(&hello);
    for (int i=0; i<50; i++) { 
        printline("main", i); 
        }
    t.join();
    return 0;
}