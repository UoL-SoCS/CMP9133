#include <iostream>

class MyClass {
public:
    int value;
    float age;
    // Copy assignment operator
    // MyClass& operator=(const MyClass& other) {
    //     if (this != &other) { // Avoid self-assignment
    //         value = other.value;
    //     }
    //     return *this;
    // }
};

int main() {
    MyClass obj1;
    obj1.value = 42;
    obj1.age = 42.0f;

    MyClass obj2;
    obj2 = obj1; // Calls the copy assignment operator

    std::cout << "obj2.value: " << obj2.value << std::endl; // Should be 42

    return 0;
}
