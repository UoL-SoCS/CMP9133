#include <iostream>

using namespace std;

class Counted
{
public:
    Counted()
    {
        Counted::count++;
    }
    ~Counted()
    {
        Counted::count--;
    }
    static int count;
};

int Counted::count = 0;

int main()
{
    Counted a, b;
    cout << "Count:   " << Counted::count << endl;
    Counted c;
    cout << "Count:   " << Counted::count << endl;
    return 0;
}