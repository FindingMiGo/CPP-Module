#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form{
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _beSigned;
	public:
		Form();
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &f);

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;
		bool getBeSigned() const;
		void beSigned(Bureaucrat &bc);

		Form &operator=(const Form &f);
		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
};

#endif
