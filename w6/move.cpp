#include <iostream>
#include <string>
#include <iomanip>

using namespace std; // Save  space  on slides.

void Print(const string &str) { cout << "lvalue: " << str << endl; }

void Print(string &&str) { cout << "rvalue: " << str << endl; }

int main() {

  string hello = "hi";
  Print(hello);
  Print("world");
  Print(std::move(hello));
  // DO NOT  access "hello" after move!
  cout << "?: " << hello << endl;

  return 0;
}