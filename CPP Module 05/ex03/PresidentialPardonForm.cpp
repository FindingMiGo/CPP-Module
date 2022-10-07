#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("PresidentialPardon", PR_SIGN, PR_EXEC) {
  target_ = "target";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form(target, PR_SIGN, PR_EXEC) {
  target_ = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &pp) {
  if (this != &pp)
    target_ = pp.target_;
  return *this;
}

void PresidentialPardonForm::executeForm(Bureaucrat const &e) const {
  if (getGradeToExec() < e.getGrade())
    throw GradeTooLowException();
  if (!getBeSigned())
    throw NoSignException();
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
};
