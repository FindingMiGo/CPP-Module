#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T> typename T::iterator easyfind(T &t, const int &num) {
  typename T::iterator itr = std::find(t.begin(), t.end(), num);
  if (itr == t.end()) {
    throw std::exception();
  }
  return itr;
}

template <typename T>
typename T::const_iterator easyfind(const T &t, const int &num) {
  typename T::const_iterator itr = std::find(t.begin(), t.end(), num);
  if (itr == t.end()) {
    throw std::exception();
  }
  return itr;
}

#endif
