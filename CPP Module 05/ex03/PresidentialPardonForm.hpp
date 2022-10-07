#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

#define PR_SIGN 25
#define PR_EXEC 5

class PresidentialPardonForm : public Form {
private:
  std::string target_;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &pp);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &pp);

  void executeForm(Bureaucrat const &e) const;
};

#endif
