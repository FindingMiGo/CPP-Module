#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain{
	private:
		std::string ideas_[100];
	public:
		Brain();
		Brain(const std::string &str);
		~Brain();
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		void printIdeas();
};

#endif
