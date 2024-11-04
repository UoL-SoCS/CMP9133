#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

class Human {

public:
  Human(int kindness) : kindness_{kindness} {}
  int kindness() const { return kindness_; }

private:
  int kindness_ = 100;
};

std::ostream& operator<<(std::ostream& os, const Human& human){
    os << "This human is this kind: " << human.kindness();
    return os;
}

int main() {

  std::vector<Human> humans = {Human{10}, Human{5}};
  for (auto&& human : humans) {
    std::cout << human << std::endl;
  }

  return 0;
}
