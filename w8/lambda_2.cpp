#include <iostream>
#include <thread>
using namespace std;

class Wrapper {
public:
    void operator()(string &msg){
        std::cout << "t1 says: " << msg << std::endl;
        msg = "Here some changes!" ;
    }
};

int main() {

    string s = "Learning C++ multithreading...";
    std::cout << std::this_thread::get_id() << std::endl;  // get ID of main thread

    std::thread t1(Wrapper(), std::ref(s));
    std::cout << t1.get_id() << std::endl;  // get ID of t1 thread

    std::thread t2 = std::move(t1);  // Using move() to copy thread, you can NOT do t2=t1
    std::cout << t2.get_id() << std::endl;  // get ID of t2 thread

    t2.join();

    cout << "From main: " << s << endl;

    return 0;
}