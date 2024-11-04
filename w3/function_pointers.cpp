#include <iostream>
using namespace std;

// Function declarations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int print(string test){
    cout << test << endl;
    return 0;
}


int main() {
    // Function pointers
    int (*funcPtr)(int, int);

    // Assigning the add function to funcPtr
    funcPtr = &add;
    cout << "Testing add function:" << funcPtr(5,3) << endl;

    // Assigning the subtract function to funcPtr
    funcPtr = &subtract;
    cout << "Testing subtract function:" << funcPtr(5,3) << endl;

    funcPtr = &print;
    cout << "Testing print function:" << funcPtr("Hello World") << endl;

    return 0;
}
