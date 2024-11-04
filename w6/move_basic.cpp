#include <iostream>

int main(){
    int a = 2;
    std::cout << "a = " << a << std::endl;
    int&& c = std::move(a);
    std::cout << "c = " << c << std::endl;
    std::cout << "a = " << a << std::endl;

    return 0;
}