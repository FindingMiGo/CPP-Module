#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

#define SH_SIGN 145
#define SH_EXEC 137

class ShrubberyCreationForm : public Form{
	private:
		std::string target_;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &sc);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &sc);
		void execute(Bureaucrat const &e) const;
};

#endif
