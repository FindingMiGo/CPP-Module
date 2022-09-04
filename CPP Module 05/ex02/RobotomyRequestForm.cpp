#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", RO_SIGN, RO_EXEC){
	_target = "target";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form(target, RO_SIGN, RO_EXEC){
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rr){
	if(this != &rr)
		_target = rr._target;
	return *this;
}

void RobotomyRequestForm::executeForm(Bureaucrat const &e) const{
	if (getGradeToExec() < e.getGrade())
		throw GradeTooLowException();
	if (!getBeSigned())
		throw NoSignException();
	std::cout << "ZAP ZAP ZAP" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0){
		std::cout << "Successful lobotomy for " << _target << std::endl;
	}else
		std::cout << "Failed lobotomy for " << _target << std::endl;

};
