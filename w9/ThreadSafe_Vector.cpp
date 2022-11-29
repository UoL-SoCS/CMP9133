#include <iostream>
#include <thread>
#include <vector>
#include "ThreadSafe_Vector.h"

void random_operation(ThreadSafe_Vector &myvector) {
    while (true) {
        int value = rand();
        if (value % 2 == 0) myvector.emplace_back(value);
        else myvector.pop_back(value);
    }
}

int main() {
    ThreadSafe_Vector myvector;
    std::thread t1(&random_operation, std::ref(myvector));
    std::thread t2(&random_operation, std::ref(myvector));
    t1.join();
    t2.join();
    std::cout << "main: empty=" << myvector.empty() << std::endl;
    return 0;
}
