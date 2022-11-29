#include <iostream>
#include <future>

bool is_prime(long x) {
    std::cout << "Calculating. Please, wait...\n";
    for (int i=2; i<x; ++i)
        if (x%i == 0)
            return false;
    return true;
}

int main () {
    long numX = 313222313;
    std::future<bool> futObj = std::async(is_prime, numX);
    std::cout << "Is " << numX << " a prime number?\n";

    bool retval = futObj.get();
    if (retval) std::cout << "Yes\n";
    else std::cout << "No\n";
    
    return 0;
}
