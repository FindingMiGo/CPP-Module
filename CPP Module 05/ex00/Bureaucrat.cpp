#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST_GRADE){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bc){
	*this = bc;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bc){
	if(this != &bc){
		_grade = bc._grade;
		_name = bc._name;
	}
	return *this;
}

std::string const &Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::promotion(){
	if (_grade <= HIGHEST_GRADE){
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::demotion(){
	if (_grade >= LOWEST_GRADE){
		throw GradeTooHighException();
	}
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "too hight";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "too low";
}
