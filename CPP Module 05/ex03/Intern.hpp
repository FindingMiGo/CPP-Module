#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &i);
  ~Intern();
  Intern &operator=(const Intern &i);
  Form *makeForm(const std::string &fName, const std::string &ftarget);

  class NoMatching : public std::exception {
    const char *what() const throw();
  };
};

#endif
