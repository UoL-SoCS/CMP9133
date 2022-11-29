#include <iostream>
#include <thread>
#include <chrono>
#include <future>

int count = 0;

void printline(std::future<int>& fo) {
    int max = fo.get();
    while (true){
       std::cout << std::this_thread::get_id() << "() count=" << count << std::endl;
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
       count++;
       if (count>max) break;
    }
    std::cout << std::this_thread::get_id() << "() ended!" << std::endl;
}

int main() {
    std::promise<int> prom;
    std::future<int> futObj = prom.get_future();
    std::thread t(printline, std::ref(futObj));
    std::cout << "Stopping main thread... " << std::endl;
    prom.set_value(15);
    t.join();
  return 0;
}

