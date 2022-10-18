#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

std::mutex _mu;   // In computer science, a lock or mutex is a synchronization primitive;
std::mutex _mu2;  // a mechanism that enforce limits on access to a resource when there are many threads of execution (Wikipedia)

void shared_print(string msg, int value){
    std::lock_guard<std::mutex> locker(_mu);
    std::lock_guard<std::mutex> locker2(_mu2);
    std::cout << msg << " : " << value << std::endl;
}

void shared_print2(string msg, int value){
    std::lock_guard<std::mutex> locker2(_mu2);
    std::lock_guard<std::mutex> locker(_mu);
    std::cout << msg << " : " << value << std::endl;
}

void count_function(){
    for (int i = 0; i > -100; i--){
        shared_print(string("From t1: "), i);
    }
}

/**
 * This program shows what is the DEADLOCK
 * "In concurrent computing, a deadlock is a state in which each member of a group waits for another member,
 * including itself, to take action, such as sending a messahe or, more commonly, release a lock" (Wikipedia)
 */
int main(){
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

    std::thread t1(count_function);
    std::cout << "t1 thread ID: " << t1.get_id() << std::endl;

    for (int i = 0; i<100; i++){
        shared_print2(string("From main: "), i);
    }

    t1.join();
    return 0;
}

