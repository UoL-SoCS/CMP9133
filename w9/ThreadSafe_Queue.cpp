#include <iostream>
#include <thread>
#include "ThreadSafe_Queue.h"

void random_operation(ThreadSafe_Queue &myqueue) {
    while (true) {
        int value = rand();
        if (value % 2 == 0) {
            myqueue.push(value);
            myqueue.emplace([value]() {
                std::thread::id id = std::this_thread::get_id();
                std::cout << "Hello from thread id " << id << ", last value=" << value << '\n';
            });
        } else {
            myqueue.pop(value);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    ThreadSafe_Queue myqueue;
    std::thread t1(&random_operation, std::ref(myqueue));
    std::thread t2(&random_operation, std::ref(myqueue));
    t1.join();
    t2.join();
    std::cout << "main: empty=" << myqueue.empty() << std::endl;
    return 0;
}
