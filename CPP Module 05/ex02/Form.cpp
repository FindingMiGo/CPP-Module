#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name_("default"), gradeToSign_(LOWEST_GRADE), gradeToExec_(LOWEST_GRADE), beSigned_(false){}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name_(name), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec), beSigned_(false){
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

Form::Form(const Form &f) : name_(f.name_), gradeToSign_(f.gradeToSign_), gradeToExec_(f.gradeToExec_), beSigned_(f.beSigned_){
	*this = f;
}

Form &Form::operator=(const Form &f){
	if (this != &f)
		beSigned_ = f.beSigned_;
	return *this;
}

void Form::beSigned(const Bureaucrat &bc){
	if (bc.getGrade() > gradeToSign_)
		throw GradeTooLowException();
	beSigned_ = true;
}

const std::string &Form::getName() const{
	return name_;
}

const int &Form::getGradeToSign() const{
	return gradeToSign_;
}

const int &Form::getGradeToExec() const{
	return gradeToExec_;
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
	return beSigned_;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form name:\t"	<< f.getName()
	<< "\ngrade to sign:\t" << f.getGradeToSign() 
	<< "\ngrade to exec:\t" << f.getGradeToExec() 
	<< "\nbe signed:\t" << f.getBeSigned();
	return os;
}
