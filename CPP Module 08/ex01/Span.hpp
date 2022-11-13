#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
#include <limits>

class Span {
private:
  unsigned int size_;
  std::vector<int> v_;

public:
  Span();
  Span(unsigned int n);
  ~Span();
  Span(const Span &s);
  Span &operator=(const Span &s);
  void addNumber(int n);
  void fill(std::vector<int> nums);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  class OverCapacity : public std::exception {
    const char *what() const throw();
  };
  class FewerElements : public std::exception {
    const char *what() const throw();
  };
};

#endif
