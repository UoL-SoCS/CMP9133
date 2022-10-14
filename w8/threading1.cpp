// threading1.cpp : Introduction to thread in C++ (C++11)

// QUESTIONS
// 1. What do you understand by thread and give one example in C++?

// ANSWERS
// 1. In every application there is a default thread -- main() inside which we can create other threads.
// 2. A thread is also known as lightweight process that can be achieved via parallelism by dividing a process into multiple threads.
//      For example: 
//      (1) The browser has multiple tabs that can be different threads.
//      (2) A UI in C++ can implement different components, i.e., threads.
//      (3) Visual Studio code editor would be using threading for auto code checking, auto completing the code (Intellisense).
//      (4) MS Word or PowerPoint must be using multiple threads, some to format the text, some to process input spelling check.

// WAYS TO CREATE THREADS IN C++
// 1. Function pointes
// 2. Lambda Functions
// 3. Functions 
// 4. Member Functions
// 5. Static Member Functions

#include <iostream>
#include <thread>
using namespace std;

void function_1() {
    std::cout << "Hello World!\n" << std::endl;
}

int main() {
    
    std::thread t1(function_1);  // t1 starts running
    // t1.join();  // main thread waits for t1 to complete
    t1.detach();  // t1 runs freely on its own as a daemon process (in background)

    // ...

    if (t1.joinable()) 
        t1.join();  // still not rejoining t1, but program will not crash
}