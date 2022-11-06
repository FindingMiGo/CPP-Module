#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, std::size_t size, void (*f)(const T &)) {
  if (!array || !f)
    return;
  for (size_t i = 0; i < size; i++) {
    f(array[i]);
  }
}

#endif
