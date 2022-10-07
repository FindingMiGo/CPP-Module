#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm()
    : Form("Robotomy", RO_SIGN, RO_EXEC) {
  target_ = "target";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form(target, RO_SIGN, RO_EXEC) {
  target_ = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rr) {
  if (this != &rr)
    target_ = rr.target_;
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &e) const {
  if (!getBeSigned())
    throw NoSignException();
  if (getGradeToExec() < e.getGrade())
    throw GradeTooLowException();
  std::cout << "ZAP ZAP ZAP... ";
  srand(time(NULL));
  if (rand() % 2 == 0) {
    std::cout << "Successful lobotomy for " << target_ << std::endl;
  } else
    std::cout << "Failed lobotomy for " << target_ << std::endl;
};
