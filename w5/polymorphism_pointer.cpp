#include <iostream>
using namespace std;

// Base class
class Square {
public:

    int width = 10;
    string name = "square";

    int getArea() {
        return (width * width);
    }

};

// Derived class
class Rectangle: public Square {
public:
    int height = 20;
    int getArea() {
        return (width * height);
    }

    
};

int main() {
    Square sqr;
    Rectangle rect;
    Square *ptr, *ptr2;

    ptr = &rect;
    // ptr2 = &sqr;

    cout << ptr->getArea() << endl;
    // cout << ptr2->getArea() << endl;

    return 0;
}
