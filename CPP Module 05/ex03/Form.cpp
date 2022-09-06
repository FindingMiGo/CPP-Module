#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(LOWEST_GRADE), _gradeToExec(LOWEST_GRADE), _beSigned(false){}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _beSigned(false){
	if (gradeToExec < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToExec > LOWEST_GRADE)
		throw GradeTooLowException();
	if (gradeToSign < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form &f) : _name(f._name), _gradeToSign(f._gradeToSign), _gradeToExec(f._gradeToExec), _beSigned(f._beSigned){
	*this = f;
}

Form &Form::operator=(const Form &f){
	if (this != &f)
		_beSigned = f._beSigned;
	return *this;
}

void Form::beSigned(const Bureaucrat &bc){
	if (bc.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_beSigned = true;
}

const std::string &Form::getName() const{
	return _name;
}

const int &Form::getGradeToSign() const{
	return _gradeToSign;
}

const int &Form::getGradeToExec() const{
	return _gradeToExec;
}

const char *Form::GradeTooHighException::what() const throw(){
	return "Grade too High";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "Grade too Low";
}

const char *Form::NoSignException::what() const throw(){
	return "Not signed";
}

bool Form::getBeSigned() const{
	return _beSigned;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form name:\t"	<< f.getName()
	<< "\ngrade to sign:\t" << f.getGradeToSign() 
	<< "\ngrade to exec:\t" << f.getGradeToExec() 
	<< "\nbe signed:\t" << f.getBeSigned();
	return os;
}
