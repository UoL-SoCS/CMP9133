#include <iostream>

using namespace std;

int main(){
    int *x;
    if (true){
        int y = 10;
        x = &y;
        cout << x << " : " << *x << endl;
    }
    cout << x << " : " << *x << endl;
    return 0;
}