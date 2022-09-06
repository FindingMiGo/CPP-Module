#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", PR_SIGN, PR_EXEC){
	_target = "target";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(target, PR_SIGN, PR_EXEC){
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &pp){
	if(this != &pp)
		_target = pp._target;
	return *this;
}

void PresidentialPardonForm::executeForm(Bureaucrat const &e) const{
	if (getGradeToExec() < e.getGrade())
		throw GradeTooLowException();
	if (!getBeSigned())
		throw NoSignException();
	std::cout << _target <<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
};
