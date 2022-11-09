#include "easyfind.hpp"
#include <iostream>

#define MAX 10

int main() {
  {
    std::vector<int> v(MAX);
    for (int i = 0; i < MAX; i++) {
      v.push_back(MAX);
    }

    try {
      std::cout << "easyfind 2\t" << *easyfind(v, 2) << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    try {
      std::cout << "easyfind 20\t" << *easyfind(v, 20) << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }
}
