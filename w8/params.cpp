#include <iostream>
#include <thread>

void hello(const char* msg, int& id) {
    std::cout << msg << "thread id=" << std::this_thread::get_id() << std::endl;
    id = 1;
}

int main() {
    
    int id = 0;
    const char* msg = "Hello concurrent world!\n";
    
    std::thread t(&hello, msg, std::ref(id));
    
    // while (id ==0) { 
    //     std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    // }
    
    std::cout << "thread id=" << id << std::endl;
    t.join();
    
    return 0;
}