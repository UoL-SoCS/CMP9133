#include <iostream>

// Declare an enum named 'Gender'
enum Gender {
    Male,   // Assigned value 0
    Female  // Assigned value 1 (next consecutive value)
};

int main() {
    // Create a variable of type 'Gender'
    Gender personGender = Dog;

    // Switch statement based on the gender
    switch (personGender) {
        case Male:
            std::cout << "Gender is Male" << std::endl;
            break;
        case Female:
            std::cout << "Gender is Female" << std::endl;
            break;
        default:
            std::cout << "Value can be Male or Female" << std::endl;
    }

    return 0;
}
