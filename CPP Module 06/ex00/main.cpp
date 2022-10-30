#include "StringConvert.hpp"
#include <float.h>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2 || argv[1][0] == '\0') {
    std::cerr << "Invalid argument" << std::endl;
    return (0);
  }
  std::string str(argv[1]);
  StringConvert s(str);
  std::cout << s;
}
