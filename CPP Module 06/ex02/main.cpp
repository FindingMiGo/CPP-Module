#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  if (a){
    std::cout << "Identified as A" << std::endl;
    return ;
  }
  B *b = dynamic_cast<B *>(p);
  if (b){
    std::cout << "Identified as B" << std::endl;
    return ;
  }
  C *c = dynamic_cast<C *>(p);
  if (c)
    std::cout << "Identified as C" << std::endl;
}

void identify(Base &p) {
  try {
    A a = dynamic_cast<A &>(p);
    std::cout << "Identified as A" << std::endl;
  } catch (const std::exception &e) {
  }
  try {
    B b = dynamic_cast<B &>(p);
    std::cout << "Identified as B" << std::endl;
  } catch (const std::exception &e) {
  }
  try {
    C c = dynamic_cast<C &>(p);
    std::cout << "Identified as C" << std::endl;
  } catch (const std::exception &e) {
  }
}

Base *generate(void) {
  srand(time(NULL));
  int random = rand() % 3;
  if (random == 0) {
    std::cout << "Generated as A" << std::endl;
    return new A();
  } else if (random == 1) {
    std::cout << "Generated as B" << std::endl;
    return new B();
  } else {
    std::cout << "Generated as C" << std::endl;
    return new C();
  }
}

int main(void) {
  Base *b = generate();

  identify(*b);
  identify(b);
}
