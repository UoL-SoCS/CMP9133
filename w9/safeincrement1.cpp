#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex mtx;

void safe_increment() {
    mtx.lock();
    count++;
    mtx.unlock();
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << std::this_thread::get_id() << ": " << count << '\n';
}

int main() {
    std::cout << "main: " << count << '\n';
    std::thread threads[10];
    for (int i=0; i<10; ++i) {
        threads[i] = std::thread(&safe_increment);
    }
    for (auto& th : threads) th.join();
    std::cout << "main: " << count << std::endl;
}
