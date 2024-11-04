#include <iostream>

using namespace std;

class myClass{
    private:
        int aVar;

    public:
        myClass() {aVar = 0;}
        void aFunction(const int *x){
            *x = 10;
            }
};

int main(){
    myClass x;
    int y;
    x.aFunction(&y);

    return 0;
}