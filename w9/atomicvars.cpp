#include <iostream>
#include <thread> 
#include <vector> 
#include <atomic>

std::atomic<bool> ready (false); 
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m (int id) {
  while (!ready) { std::this_thread::yield(); }
  for (int i=0; i<1000000; ++i) {}
  if (!winner.test_and_set()) { std::cout << "Thread #" << id << " won!\n"; }
}

int main () {
  std::vector<std::thread> threads;
  std::cout << "Spawning 10 threads that count to 1 million...\n";
  for (int i=1; i<=10; ++i)
      threads.push_back(std::thread(count1m,i));
  ready = true;
  for (auto& th : threads) th.join();
  return 0;
}
