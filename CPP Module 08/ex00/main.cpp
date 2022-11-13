#include "easyfind.hpp"

#define MAX 10

int main() {
  {
    std::cout << "vector" << std::endl;
    std::vector<int> v(MAX);
    for (int i = 0; i < MAX; i++) {
      v.push_back(i);
    }

    try {
      std::cout << "easyfind 2\t" << *easyfind(v, 2) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Not found" << std::endl;
    }
    try {
      std::cout << "easyfind 9\t" << *easyfind(v, 9) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Not found" << std::endl;
    }
    try {
      std::cout << "easyfind 20\t" << *easyfind(v, 20) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Not found" << std::endl;
    }
  }
  {
    std::cout << "list" << std::endl;
    std::list<int> v(MAX);
    for (int i = 0; i < MAX; i++) {
      v.push_back(i);
    }

    try {
      std::cout << "easyfind 2\t" << *easyfind(v, 2) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Not found" << std::endl;
    }
    try {
      std::cout << "easyfind 9\t" << *easyfind(v, 9) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Not found" << std::endl;
    }
    try {
      std::cout << "easyfind 20\t" << *easyfind(v, 20) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Not found" << std::endl;
    }
  }
}
