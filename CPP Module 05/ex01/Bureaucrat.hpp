#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form;

class Bureaucrat {
private:
  std::string name_;
  int grade_;

public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &bc);
  Bureaucrat &operator=(const Bureaucrat &bc);
  std::string const &getName() const;
  int getGrade() const;
  void promotion();
  void demotion();
  void signForm(Form &f) const;

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bc);

#endif
