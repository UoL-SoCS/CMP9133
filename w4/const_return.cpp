#include <iostream>

using namespace std;

class myClass{
    private:
        int aVar;

    public:
        myClass() {aVar = 0;}
        int &Value(void) {return aVar;};
        const int &Value(void) const {return aVar;};

};


int main(){
    const myClass x;
    int y = x.Value();
    std::cout << y << std::endl;
    
    myClass z;
    z.Value() = 10;	
    std::cout << z.Value() << std::endl;

    return 0;
}