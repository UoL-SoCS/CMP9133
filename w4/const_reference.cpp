#include <iostream>

using namespace std;

int main(){
    int x = 10;
    const int &y = x;

    cout << y << endl;
    y = 12;
    cout << y << endl;
}