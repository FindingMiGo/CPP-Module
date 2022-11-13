#include "Span.hpp"
#include <iostream>

#define SIZE 10000
#define DIFF 2
#define OFFSET 0

int main() {
  {
    std::cout << "=====" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
  }

  std::cout << std::endl;
  {
    std::cout << "=====" << std::endl;
    Span sp = Span(2);
    sp.addNumber(std::numeric_limits<int>::max());
    sp.addNumber(std::numeric_limits<int>::min());
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
  }

  std::cout << std::endl;
  {
    std::cout << "=====" << std::endl;
    Span sp(0);
    try {
      sp.addNumber(1);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    std::cout << "=====" << std::endl;
    Span sp(1);
    try {
      std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    std::cout << "=====" << std::endl;
    Span sp(SIZE);
    int array[SIZE];
    for (int i = 0; i < SIZE; i++) {
      array[i] = OFFSET + i * DIFF;
    }
    std::vector<int> v(array, array + SIZE);
    sp.fill(v);
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "head: " << v.at(0) << std::endl;
    std::cout << "tail: " << v.at(SIZE - 1) << std::endl;
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
  }
  return 0;
}
