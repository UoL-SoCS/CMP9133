#include <iostream>

using namespace std;

int main() {
    int *y = new int[10];
    y[0] = 5;
    std::cout << "address: " << y << std::endl;
    std::cout << "content: " << y[0] << std::endl;

    delete [] y;
    std::cout << "\naddress: " << y << std::endl;
    std::cout << "content: " << y[0] << std::endl;
    
    return 0;
}