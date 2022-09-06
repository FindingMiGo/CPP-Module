#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat a("test", 1);
		a.signForm(*rrf);
		rrf->executeForm(a);
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender Brain");
		Bureaucrat a("test", 1);
		a.signForm(*rrf);
		rrf->executeForm(a);
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Intern");
		Bureaucrat a("test", 1);
		a.signForm(*rrf);
		rrf->executeForm(a);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	return (0);
}
