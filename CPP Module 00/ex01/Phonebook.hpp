#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class phonebook
{
	private:
		Contact			contactlist[8];
		unsigned int	num;
		void			add();
		void			search();
	public:
		phonebook();
		void	repl();

};

#endif
