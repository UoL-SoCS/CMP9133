#include <iostream>

using namespace std;

int main(){
    int x = 10;
    int *y = &x;

    *y = 10;

    const int z = 10;
    int *w = &z;

    *w = 10;

}