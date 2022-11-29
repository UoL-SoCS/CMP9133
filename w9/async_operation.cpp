#include <iostream>
#include <future>

void is_prime(std::future<long>& fo) {
    long x = fo.get();
    std::cout << "Calculating. Please, wait...\n";
    for (int i=2; i<x; ++i) {
        if (x%i == 0) {
            std::cout << "No\n";
            break;
        }
    }
    std::cout << "Yes\n";
}

int main () {
    long numX = 313222313;
    std::promise<long> prom;
    std::future<long> futObj = prom.get_future();
    std::thread t(is_prime, std::ref(futObj));
    
    std::cout << "Is " << numX << " a prime number?\n";
    prom.set_value(numX);
    t.join();
    
    return 0;
}
