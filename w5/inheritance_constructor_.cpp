#include <iostream>
using namespace std;

// Base class
class Square {
public:

    int width;
    string name = "square";

    Square() {
        width = 10;
    };
};

// Derived class
class Rectangle: public Square {
public:
    int height;
    Rectangle() {
        height = 20;
    };  
};

int main() {
    Rectangle rect;
    
    std::cout << rect.width << std::endl;
    std::cout << rect.height << std::endl;

    return 0;
}
