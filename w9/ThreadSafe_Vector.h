#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class ThreadSafe_Vector {
private:
    std::mutex mtx;
    std::vector<int> data;
public:
    void emplace_back(int value) {
        std::lock_guard<std::mutex> lock(mtx);
        data.emplace_back(value);
        std::cout << std::this_thread::get_id() << " appending " << value << std::endl;
    }
    
    void pop_back(int &value) {
        std::lock_guard<std::mutex> lock(mtx);
        if(!data.empty()) {
            value = data.back();
            data.pop_back();
            std::cout << std::this_thread::get_id() << " removing " << value << std::endl;
        }
    }
    
    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << std::this_thread::get_id() << " size=" << data.size() << std::endl;
        return data.empty();
    }
};
