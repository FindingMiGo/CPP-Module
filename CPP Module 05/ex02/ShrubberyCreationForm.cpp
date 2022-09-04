#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", SH_SIGN, SH_EXEC){
	_target = "target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form(target, SH_SIGN, SH_EXEC){
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &sc){
	if(this != &sc)
		_target = sc._target;
	return *this;
}

void ShrubberyCreationForm::executeForm(Bureaucrat const &e) const{
	if (getGradeToExec() < e.getGrade())
		throw GradeTooLowException();
	if (!getBeSigned())
		throw NoSignException();
	std::string tree =	"木\n";
	std::string fileName = _target + "_shrubery";
	std::ofstream ofs(fileName.c_str());
	if (ofs.fail()){
		throw ("error output file open");
	}
	ofs << tree << std::endl;
	ofs.close();
};
