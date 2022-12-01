#include <iostream>
#include <thread>
#include <stack>
#include <mutex>

using namespace std;

class ThreadSafe_Stack {
private:
    std::mutex mtx;
    std::stack<int> data;
public:
    void push(int value) {
        mtx.lock();
        data.push(value);
        mtx.unlock();
        std::cout << std::this_thread::get_id() << " pushing " << value << std::endl;
    }
    
    void pop(int &value) {
        if(!data.empty()) {
            mtx.lock();
            value = data.top();
            data.pop();
            mtx.unlock();
            std::cout << std::this_thread::get_id() << " popping " << value << std::endl;
        }
    }
    
    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << std::this_thread::get_id() << " size=" << data.size() << std::endl;
        return data.empty();
    }
};
