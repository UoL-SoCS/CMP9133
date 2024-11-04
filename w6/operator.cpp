#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

class Human {

public:
  Human(int kindness) : kindness_{kindness} {}

  // bool operator<(const Human &other) const {

  //   return kindness_ < other.kindness_;
  // }

  int kindness() const { return kindness_; }

private:
  int kindness_ = 100;
};

int main() {

  std::vector<Human> humans = {Human{10}, Human{5}};
  std::cout << humans[0].kindness() << ", " << humans[1].kindness() << std::endl;
  std::sort(humans.begin(), humans.end());
  std::cout << humans[0].kindness() << ", " << humans[1].kindness() << std::endl;

  return 0;
}
