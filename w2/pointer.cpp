#include <iostream>

using namespace std;
int main(){
    int x;
    x = 10;
    int *y;
    y = &x;

    cout << "x = " << x << endl;
    *y = 12;
    cout << "x = " << x << endl;
    // y = &x;

    // int *z;
    // std::cout << (z == NULL) << std::endl;
    // std::cout << z << std::endl;

    return 0;
}