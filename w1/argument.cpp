#include <iostream>

int main(int argc, char** argv){
        std::cout << "There are " << argc << " arguments: " << std::endl;
        for (int i=0; i<argc; ++i){
                std::cout << argv[i] << std::endl;
        }
}