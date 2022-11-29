#include <iostream>
#include <future>

void is_prime(long x, std::promise<bool> prom) {
    std::cout << "Calculating. Please, wait...\n";
    for (int i=2; i<x; ++i)
        if (x%i == 0) {
            prom.set_value(false);
            return;
        }
    prom.set_value(true);
}

int main () {
    long numX = 313222313;
    std::promise<bool> prom;
    std::future<bool> futObj = prom.get_future();
    std::thread t(&is_prime, numX, std::move(prom));

    std::cout << "Is " << numX << " a prime number?\n";
    bool retval = futObj.get();
    if (retval) std::cout << "Yes\n";
    else std::cout << "No\n";
    t.join();
    
    return 0;
}
