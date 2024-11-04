#include <iostream>

using namespace std;

int main(){
    int x;
    int &y = x;

    x = 9;
    y = 10;

    y++;
    std::cout << y << std::endl;
    std::cout << x << std::endl;
}