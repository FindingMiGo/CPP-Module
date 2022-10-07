#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;

Bureaucrat::Bureaucrat() : name_("default"), grade_(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name_(name), grade_(grade) {
  if (grade < HIGHEST_GRADE)
    throw GradeTooHighException();
  if (grade > LOWEST_GRADE)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bc) { *this = bc; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bc) {
  if (this != &bc) {
    grade_ = bc.grade_;
    name_ = bc.name_;
  }
  return *this;
}

std::string const &Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::promotion() {
  if (grade_ <= HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  grade_--;
}

void Bureaucrat::demotion() {
  if (grade_ >= LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bc) {
  os << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
  return os;
}

void Bureaucrat::signForm(Form &f) const {
  try {
    f.beSigned(*this);
    std::cout << name_ << " signed " << f.getName() << std::endl;
  } catch (std::exception const &e) {
    std::cout << name_ << " couldn't sign " << f.getName() << " because "
              << e.what() << " ." << std::endl;
  }
}
