#include <iostream>
using namespace std;

// Base class
class Square {
public:

    int width = 10;
    string name = "square";

    virtual int getArea() {
        return (width * width);
    }


};

// Derived class
class Rectangle: public Square {
public:
    int height = 20;
    int getArea() override{
        return (width * height);
    }

    
};

int main() {
    Square sqr;
    Rectangle rect;

    cout << sqr.getArea() << endl;
    cout << rect.getArea() << endl;

    cout << sqr.name << endl;
    cout << rect.name << endl;

    return 0;
}
