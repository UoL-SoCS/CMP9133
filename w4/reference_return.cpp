#include <iostream>

using namespace std;

class myClass{
    private:
        int aVar;

    public:
        int &Value(void) {return aVar;}
};

int main(){
    myClass x;
    int y = x.Value();  // int variable
    std::cout << y << std::endl;	
    
    // int &z = x.Value();  // reference
    x.Value() = 10;

    std::cout << x.Value() << std::endl;
}