#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello concurrent world!\n";
}

int main() {
    std::thread t(&hello);  // t starts running
    // t.join();  // main thread waits for t to finish
    t.detach();  // t runs freely on its own as a deamon process (in background)
    return 0;
}