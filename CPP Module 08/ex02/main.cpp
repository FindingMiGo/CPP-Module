#include "MutantStack.hpp"

void test1() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void test1_const() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::const_iterator it = mstack.begin();
  MutantStack<int>::const_iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void test2() {
  MutantStack<int> mstack;
  std::list<int> lst;

  for (int i = 0; i < 10; i++) {
    mstack.push(i);
    lst.push_back(i);
  }
  MutantStack<int>::iterator mitr = mstack.begin();
  std::list<int>::iterator litr = lst.begin();
  for (int i = 0; i < 10; i++) {
    std::cout << "mstack: " << *mitr << "\tlist: " << *litr << std::endl;
  }
}

int main() {
  std::cout << "subject test\n";
  test1();
  std::cout << "\nsubject test(const)\n";
  test1_const();
  std::cout << "\ntest to compare with stacks and lists\n";
  test2();
  return 0;
}
