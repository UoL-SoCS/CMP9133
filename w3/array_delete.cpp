#include <iostream>
using namespace std;

int main() {
    // Specify the size of the array
    int size = 5;
    
    // Dynamically allocate an array of integers
    int* array = new int[size];
    
    // Assign values to the array elements
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;  // Assign values 1, 2, 3, 4, 5
    }
    
    // Display the values to confirm allocation
    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    // Delete the dynamically allocated array
    delete[] array;
    
    // Set pointer to nullptr to avoid dangling pointer
    array = nullptr;
    
    cout << "Array memory has been freed." << endl;
    
    return 0;
}
