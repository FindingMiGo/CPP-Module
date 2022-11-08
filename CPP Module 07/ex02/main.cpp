#include "Array.hpp"
#include <iostream>
#include <stdlib.h>

#define MAX 10

template <typename T> void test(const Array<T> &a) {
  try {
    std::cout << a[MAX + 1] << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << a[-1] << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

int main() {
  {
    Array<int> int_arr(MAX);
    Array<int> arr;

    for (unsigned int i = 0; i < MAX; i++) {
      int_arr[i] = i;
    }
    arr = int_arr;
    for (unsigned int i = 0; i < MAX; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    test(arr);
  }

  {
    const Array<int> int_arr(MAX);

    for (unsigned int i = 0; i < MAX; i++) {
      std::cout << int_arr[i] << " ";
    }
    std::cout << std::endl;
    test(int_arr);
  }

  {
    Array<char> chr_arr(MAX);
    for (unsigned int i = 0; i < MAX; i++) {
      chr_arr[i] = 'a' + i;
    }
    Array<char> arr(chr_arr);
    for (unsigned int i = 0; i < MAX; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    test(arr);
  }

  {
    Array<std::string> str_arr(MAX);
    for (unsigned int i = 0; i < MAX; i++) {
      str_arr[i] = "aaaaa";
    }
    Array<std::string> arr(str_arr);
    for (unsigned int i = 0; i < MAX; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    test(arr);
  }
  return 0;
}
