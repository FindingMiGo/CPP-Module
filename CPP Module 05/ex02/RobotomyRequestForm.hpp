#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>

#define RO_SIGN 72
#define RO_EXEC 45

class RobotomyRequestForm : public Form {
private:
  std::string target_;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &r);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rr);

  void execute(Bureaucrat const &e) const;
};

#endif
