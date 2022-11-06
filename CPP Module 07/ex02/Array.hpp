#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T> class Array {
private:
  T *elements_;
  unsigned int size_;

public:
  Array();
  Array(unsigned int i);
  ~Array();
  Array(const Array &a);
  Array &operator=(const Array &a);
  T &operator[](const unsigned int &i);
  class OutOfBoundsException : public std::exception {
  public:
    const char *what() const throw();
  };
};

template <typename T> Array<T>::Array() {
  elements_ = NULL;
  size_ = 0;
}

template <typename T> Array<T>::Array(unsigned int i) {
  elements_ = new T[i];
  size_ = i;
}

template <typename T> Array<T>::~Array() { delete[] elements_; };

template <typename T> Array<T>::Array(const Array &a) {
  size_ = a.size_;
  elements_ = new T[a.size_];
  for (unsigned int i = 0; i < size_; i++) {
    elements_[i] = a.elements_[i];
  }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &a) {
  if (this != &a) {
    delete[] elements_;
    size_ = a.size_;
    elements_ = new T[size_];
    for (unsigned int i = 0; i < size_; i++) {
      elements_[i] = a.elements_[i];
    }
  }
  return (*this);
};

template <typename T> T &Array<T>::operator[](const unsigned int &i) {
  if (i >= size_) {
    throw OutOfBoundsException();
  } else {
    return elements_[i];
  }
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
  return "Out of Bounds";
}

#endif
