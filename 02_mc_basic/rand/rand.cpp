#include <iostream>
#include <random>

int main() {
  std::mt19937 mt(1);
  std::uniform_real_distribution<> ud(0.0, 1.0);
  for (int i = 0; i < 5; i++) {
    std::cout << ud(mt) << std::endl;
  }
}
