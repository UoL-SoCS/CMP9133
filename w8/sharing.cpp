#include <iostream>
#include <thread>

void hello() {
    
    for (int i=0; i<100; i++) {
    std::cout << "hello() i=" << i << std::endl;
    }
}

int main() {
    
    std::thread t(&hello);
    
    for (int i=0; i<100; i++) {
        std::cout << "main() i=" << i << std::endl;
    }
    
    t.join();
    return 0;
}