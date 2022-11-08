#include "iter.hpp"
#include <iostream>

template <typename T> void print(const T &str) {
  std::cout << str << std::endl;
}

int main() {
  {
    int array[] = {1, 2, 3, 4};
    iter(array, sizeof(array) / sizeof(array[0]), print);
  }
  std::cout << std::endl;
  {
    char array[] = {'a', 'b', 'c', 'd'};
    iter(array, sizeof(array) / sizeof(array[0]), print);
  }
  std::cout << std::endl;
  {
    char array[5][4] = {"aaa", "bbb", "ccc", "ddd", "eee"};
    iter(array, sizeof(array) / sizeof(array[0]), print);
  }
  std::cout << std::endl;
  {
    std::string array[] = {"aa", "bb", "cc", "ee", "ff", "gg"};
    iter(array, sizeof(array) / sizeof(array[0]), print);
  }
}
