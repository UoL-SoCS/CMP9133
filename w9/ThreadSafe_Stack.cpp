#include <iostream>
#include <thread>
#include "ThreadSafe_Stack.h"

void random_operation(ThreadSafe_Stack &mystack) {
    while (true) {
        int value = rand();
        if (value % 2 == 0) mystack.push(value);
        else mystack.pop(value);
    }
}

int main() {
    ThreadSafe_Stack mystack;
    std::thread t1(&random_operation, std::ref(mystack));
    std::thread t2(&random_operation, std::ref(mystack));
    t1.join();
    t2.join();
    std::cout << "main: empty=" << mystack.empty() << std::endl;
    return 0;
}
