#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  {
    Intern someRandomIntern;
    Form *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat a("test", 1);
    a.signForm(*rrf);
    a.executeForm(*rrf);
    std::cout << *rrf << std::endl;
    delete rrf;
  }

  std::cout << std::endl;

  {
    Intern someRandomIntern;
    Form *rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender Brain");
    Bureaucrat a("test", 1);
    a.signForm(*rrf);
    a.executeForm(*rrf);
    std::cout << *rrf << std::endl;
    delete rrf;
  }

  std::cout << std::endl;

  {
    Intern someRandomIntern;
    Form *rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Intern");
    Bureaucrat a("test", 1);
    a.signForm(*rrf);
    a.executeForm(*rrf);
    std::cout << *rrf << std::endl;
    delete rrf;
  }
  return (0);
}
