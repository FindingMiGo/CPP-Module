#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constuctor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = 'B';
}

Brain::Brain(const Brain &b){
	std::cout << "Brain copy Constuctor called" << std::endl;
	*this = b;
}

Brain::~Brain(){
	std::cout << "Brain destuctor called" << std::endl;
}

Brain &Brain::operator=(const Brain &b){
	if (this != &b)	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = b._ideas[i];
	}
	return *this;
}
