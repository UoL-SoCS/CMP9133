#include <iostream>

using namespace std;

class myClass{
    public:
        int aVar;
        myClass() { aVar = 0; }
        myClass(int i) { aVar = i; }
};

int main(int argc, char* argv[]){
    myClass *y = new myClass;
    y->aVar = 0;
    std::cout << y->aVar << std::endl;
    delete y;
    
    y = new myClass;
    y->aVar = 10;
    std::cout << y->aVar << std::endl;
    
    return 0;
}