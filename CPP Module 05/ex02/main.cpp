#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void test(Bureaucrat &b, Form &f){
	try	{
		std::cout << b << std::endl;
		std::cout << "Try to sign : ";
		f.beSigned(b);
		std::cout << "Success\nTry to Excute : ";
		f.executeForm(b);
		std::cout << "Success\n";
		std::cout << f << std::endl;
	} catch (std::exception &e)	{
		std::cout << "Failure\n";
		std::cout << e.what() << std::endl;
	}
}

void test_robotomy(Bureaucrat &b, Form &f){
	try	{
		std::cout << b << std::endl;
		std::cout << "Try to sign : ";
		f.beSigned(b);
		std::cout << "Success\nTry to Excute : \n";
		f.executeForm(b);
		std::cout << f << std::endl;
	} catch (std::exception &e)	{
		std::cout << "Failure\n";
		std::cout << e.what() << std::endl;
	}
}

int main(){
	{
		std::cout << "===Test to sign and execute by high enough grade bureaucrat (ShrubberyCreation)===\n";
		Bureaucrat b("b", 137);
		ShrubberyCreationForm f("f");
		test(b, f);
	}

	std::cout << std::endl;
	{
		std::cout << "===Test to sign and execute by bureaucrat who can only sign (ShrubberyCreation)===\n";
		Bureaucrat b("b", 145);
		ShrubberyCreationForm f("f");
		test(b, f);
	}

	std::cout << std::endl;
	{
		std::cout << "===Test to sign and execute by lowest grade bureaucrat (ShrubberyCreation)===\n";
		Bureaucrat b("b", 150);
		ShrubberyCreationForm f("f");
		test(b, f);
	}

	std::cout << std::endl;
	try {
		std::cout << "===Test to execute unsigned form (ShrubberyCreation)===\n";
		Bureaucrat b("b", 1);
		ShrubberyCreationForm f("f");
		std::cout << "Try to Execute : ";
		f.executeForm(b);
		std::cout << "Success\n";
		std::cout << f << std::endl;
	} catch (std::exception &e)	{
		std::cout << "Failure\n";
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	{
		std::cout << "===Test to sign and execute by high enough grade bureaucrat (RobotomyRequest)===\n";
		Bureaucrat b("Walter Rudolf Hess", 1);
		RobotomyRequestForm f("Egas Moniz");
		test_robotomy(b, f);
	}

		std::cout << std::endl;
	{
		std::cout << "===Test to sign and execute by bureaucrat who can only sign (RobotomyRequest)===\n";
		Bureaucrat b("b", 72);
		RobotomyRequestForm f("f");
		test_robotomy(b, f);
	}

	std::cout << std::endl;
	{
		std::cout << "===Test to sign and execute by lowest grade bureaucrat (RobotomyRequest)===\n";
		Bureaucrat b("b", 150);
		RobotomyRequestForm f("f");
		test_robotomy(b, f);
	}

	std::cout << std::endl;
	try {
		std::cout << "===Test to execute unsigned form (RobotomyRequest)===\n";
		Bureaucrat b("b", 1);
		RobotomyRequestForm f("f");
		std::cout << "Try to Execute : ";
		f.executeForm(b);
		std::cout << "Success\n";
		std::cout << f << std::endl;
	} catch (std::exception &e)	{
		std::cout << "Failure\n";
		std::cout << e.what() << std::endl;
	}

	return (0);
}
