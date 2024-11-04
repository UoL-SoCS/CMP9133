#include <iostream>

using namespace std;

int main(){
    int x[10];
    int *y = x;
    int *z = &x[0];
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;	
    return 0;
}