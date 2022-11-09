#include "Span.hpp"

Span::Span() {
  size_ = 0;
  v_.reserve(size_);
}

Span::Span(unsigned int n) {
  size_ = n;
  v_.reserve(n);
}
Span::~Span() {}

Span::Span(const Span &s) { *this = s; }

Span &Span::operator=(const Span &s) {
  if (this != &s) {
    v_.reserve(s.size_);
    v_ = s.v_;
    size_ = s.size_;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (size_ <= v_.size())
    throw OverCapacity();
  v_.push_back(n);
}

int Span::shortestSpan() {
  if (v_.size() < 2)
    throw FewerElements();
  std::vector<int> tmp(v_);
  std::sort(tmp.begin(), tmp.end());
  unsigned int span = std::numeric_limits<unsigned int>::max();
  std::vector<int>::iterator itr = tmp.begin();
  std::vector<int>::iterator end = tmp.end();
  span = std::abs(*itr - *(itr + 1));
  for (; (itr + 1) != end; itr++) {
    if (span > std::abs(*itr - *(itr + 1)))
      span = std::abs(*itr - *(itr + 1));
  }
  return span;
}

int Span::longestSpan() {
  if (v_.size() < 2)
    throw FewerElements();
  int max = *std::max_element(v_.begin(), v_.end());
  int min = *std::min_element(v_.begin(), v_.end());
  return max - min;
}

const char *Span::OverCapacity::what() const throw() { return "Over capacity"; }
const char *Span::FewerElements::what() const throw() {
  return "Fewer elements for comparison";
}

void Span::fill(std::vector<int> nums) {
  if (nums.size() > v_.capacity() - v_.size())
    throw OverCapacity();
  std::vector<int>::iterator end = nums.end();
  for (std::vector<int>::iterator itr = nums.begin(); itr != end; ++itr) {
    v_.push_back(*itr);
  }
}
