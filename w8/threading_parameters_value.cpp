#include <iostream>
#include <thread>
using namespace std;

class Wrapper {
public:
    void operator()(string msg){
        std::cout << "t1 says: " << msg << std::endl;
        msg = "Here some changes!" ;
    }
};

int main() {

    string s = "Learning C++ multithreading...";
    std::thread t1(Wrapper(), s); // Passing parameters by VALUE, which is inefficient!

    t1.join();

    cout << "From main: " << s << endl;

    return 0;
}