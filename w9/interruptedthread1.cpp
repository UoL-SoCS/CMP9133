#include <iostream>
#include <thread>
#include <chrono>
#include <future>

int count = 0;

void printline(std::future<void> futureObj) {
    while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout){
       std::cout << std::this_thread::get_id() << "() count=" << count << std::endl;
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
       count++;
    }
    std::cout << std::this_thread::get_id() << "() ended!" << std::endl;
}

int main() {
  std::promise<void> exitSignal;
  std::future<void> futureObj = exitSignal.get_future();
  std::thread t(&printline, std::move(futureObj));
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Stopping thread... " << std::endl;
  exitSignal.set_value();
  t.join();
  return 0;
}

