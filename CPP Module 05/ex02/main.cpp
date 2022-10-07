#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test(Bureaucrat &b, Form &f, bool sign) {
  std::cout << b << std::endl;
  if (sign == true) {
	b.signForm(f);
  }
  b.executeForm(f);
}

int main() {
  {
    std::cout << "===Test to sign and execute by high enough grade bureaucrat "
                 "(ShrubberyCreation)===\n";
    Bureaucrat b("b", 137);
    ShrubberyCreationForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by bureaucrat who can only sign "
                 "(ShrubberyCreation)===\n";
    Bureaucrat b("b", 145);
    ShrubberyCreationForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by lowest grade bureaucrat "
                 "(ShrubberyCreation)===\n";
    Bureaucrat b("b", 150);
    ShrubberyCreationForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to execute unsigned form (ShrubberyCreation)===\n";
    Bureaucrat b("b", 1);
    ShrubberyCreationForm f("f");
    test(b, f, false);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by high enough grade bureaucrat "
                 "(RobotomyRequest)===\n";
    Bureaucrat b("Walter Rudolf Hess", 1);
    RobotomyRequestForm f("Egas Moniz");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by bureaucrat who can only sign "
                 "(RobotomyRequest)===\n";
    Bureaucrat b("b", 72);
    RobotomyRequestForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by lowest grade bureaucrat "
                 "(RobotomyRequest)===\n";
    Bureaucrat b("b", 150);
    RobotomyRequestForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to execute unsigned form (RobotomyRequest)===\n";
    Bureaucrat b("b", 1);
    RobotomyRequestForm f("f");
    test(b, f, false);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by high enough grade bureaucrat "
                 "(PresidentialPardonForm)===\n";
    Bureaucrat b("Walter Rudolf Hess", 1);
    PresidentialPardonForm f("Egas Moniz");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by bureaucrat who can only sign "
                 "(PresidentialPardonForm)===\n";
    Bureaucrat b("b", 72);
    PresidentialPardonForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout << "===Test to sign and execute by lowest grade bureaucrat "
                 "(PresidentialPardonForm)===\n";
    Bureaucrat b("b", 150);
    PresidentialPardonForm f("f");
    test(b, f, true);
  }

  std::cout << std::endl;
  {
    std::cout
        << "===Test to execute unsigned form (PresidentialPardonForm)===\n";
    Bureaucrat b("b", 1);
    PresidentialPardonForm f("f");
    test(b, f, false);
  }

  return (0);
}
