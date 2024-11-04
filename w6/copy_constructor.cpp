#include <iostream>
#include <cstring>
using namespace std;

class Student {
    int rollNumber;
    char name[50];
    double tuitionFee;

public:
    // Parameterized constructor
    Student(int roll, char n[], double fee) {
        rollNumber = roll;
        strcpy(name, n);
        tuitionFee = fee;
    }

    // Copy constructor
    Student(Student &other) {
        rollNumber = other.rollNumber;
        strcpy(name, other.name);
        tuitionFee = other.tuitionFee;
    }

    void display() {
        cout << "Roll Number: " << rollNumber << "\tName: " << name << "\tTuition Fee: " << tuitionFee << endl;
    }
};

int main() {
    // Creating an object using parameterized constructor
    Student s1(1001, "Adam", 10000);
    cout << "Original Student:" << endl;
    s1.display();

    // Creating another object using copy constructor
    Student adam(s1);
    cout << "\nCopied Student:" << endl;
    adam.display();

    return 0;
}
