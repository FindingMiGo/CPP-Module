#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &it) { *this = it; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &it) {
  if (this != &it) {
    *this = it;
  }
  return *this;
}

Form *Intern::makeForm(const std::string &fName, const std::string &ftarget) {
  int i = (fName == "shrubbery creation") | (fName == "robotomy request") * 2 |
          (fName == "presidential pardon") * 3;
  try {
    switch (i) {
    case 1:
      std::cout << "Intern creates " << fName << std::endl;
      return new ShrubberyCreationForm(ftarget);
    case 2:
      std::cout << "Intern creates " << fName << std::endl;
      return new RobotomyRequestForm(ftarget);
    case 3:
      std::cout << "Intern creates " << fName << std::endl;
      return new PresidentialPardonForm(ftarget);
    default:
      throw NoMatching();
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return NULL;
}

const char *Intern::NoMatching::what() const throw() {
  return "There are no matching forms.";
}
