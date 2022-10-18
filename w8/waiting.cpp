#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int i = 0;

void waits() {
    std::unique_lock<std::mutex> lk(mtx);
    std::cout << "Waiting... \n";
    cv.wait(lk, []{ return i == 1; });
    std::cout << "...finished waiting. i == 1\n";
}

void signals() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Notifying...\n";
    cv.notify_all();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    i = 1;
    std::cout << "Notifying again...\n";
    cv.notify_all();
}

int main() {
    std::thread t1(waits), t2(waits), t3(waits), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}