#ifndef STRINGCONVERT_HPP
#define STRINGCONVERT_HPP

#include <cerrno>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string>

enum Type { Char, Int, Float, Double, Incorrect };

class StringConvert {
private:
  std::string input_;
  size_t size_;
  char c_;
  int i_;
  float f_;
  double d_;
  Type t_;
  bool impossible_C_;
  bool impossible_I_;
  bool impossible_F_;
  bool impossible_D_;

public:
  StringConvert();
  StringConvert(std::string &str);
  ~StringConvert();
  Type detectType();
  bool isChar();
  bool isInt();
  bool isFloat();
  bool isDouble();
  void castStr();
  void printChar(std::ostream &os) const;
  void printInt(std::ostream &os) const;
  void printFloat(std::ostream &os) const;
  void printDouble(std::ostream &os) const;
  void printType(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, const StringConvert &c);

#endif
