#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

std::mutex mu;  // In computer science, a lock or mutex is a synchronization primitive;
                // a mechanism that enforce limits on access to a resource when there are many threads of execution (Wikipedia)

void shared_print(string msg, int id){

    std::lock_guard<std::mutex> guard(mu);  // To handle with exception between LOCK and UNLOCK
    mu.lock();  // LOCK the mutex
    std::cout << msg << std::endl;
    mu.unlock(); // UNLOCK the mutex
}                

void count_function(){

    for (int i = 0; i > -100; i--){
        shared_print(string("Front t1: "), i);
    }
}

int main(){

    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

    std::thread t1(count_function);
    std::cout << "t1 thread ID: " << t1.get_id() << std::endl;

    for (int i = 0; i<100; i++){
        shared_print(string("From main: "), i);
    }

    t1.join();
    // This program shows RACE CONDITION, that is different threads race for running function. TRY TO AVOID!
    return 0;
}

/**
 * Avoiding Data Race:
 * 1. Use mutex to synchronize the data access.
 * 2. Never leak a handle of data to outside.
 * 3. Design interface appropriately. 
 */