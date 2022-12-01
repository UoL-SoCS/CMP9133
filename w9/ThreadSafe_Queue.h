#include <iostream>
#include <thread>
#include <queue>
#include <future>
#include <mutex>
#include <functional>

using namespace std;

class ThreadSafe_Queue {
private:
    std::mutex mtx;
    std::queue<int> data;
    std::queue<std::function<void()>> tasks;
public:
    void push(int value) {
        std::lock_guard<std::mutex> lock(mtx);
        data.push(value);
        std::cout << std::this_thread::get_id() << " pushing " << value << std::endl;
    }
    
    void pop(int &value) {
        if (!data.empty()) {
            std::lock_guard<std::mutex> lock(mtx);
            value = data.front();
            data.pop();
            std::cout << std::this_thread::get_id() << " removing " << value << std::endl;
        }
        if (!tasks.empty()) {
            std::function<void()> task; {
                std::lock_guard<std::mutex> lock(mtx);
                task = std::move(this->tasks.front());
                this->tasks.pop();
            }
            task();
            
        }
    }
    
    template<class F, class... Args>
    auto emplace(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
        std::lock_guard<std::mutex> lock(mtx);
        using return_type = typename std::result_of<F(Args...)>::type;
        auto task = std::make_shared<std::packaged_task<return_type()>>(
                    std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        tasks.emplace([task](){ (*task)(); });
        std::cout << "data.size()=" << data.size() << " tasks.size()=" << tasks.size() << '\n';
        return task->get_future();
    }
    
    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << std::this_thread::get_id() << " size=" << data.size() << std::endl;
        return data.empty() || tasks.empty();
    }
};
