#include <iostream>

class MyClass{
    private:
        int aVar;

    public:
        int &func(void) {return aVar;}
};

int main(){
    MyClass x;
    int &y = x.func();
    y = 10;
    
    std::cout << y << std::endl;
    std::cout << x.func() << std::endl;
    
    x.func() = 5;
    std::cout << y << std::endl;

}