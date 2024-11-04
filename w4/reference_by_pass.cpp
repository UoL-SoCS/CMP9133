#include <iostream>

void MyFunction(int &x){
    x = 10;
}

int main(){
    int y = 5;
    MyFunction(y);
    std::cout << y << std::endl;
}