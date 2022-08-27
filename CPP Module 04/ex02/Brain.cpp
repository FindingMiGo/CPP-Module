#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Constuctor called (Brain)" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = 'B';
}

Brain::Brain(const Brain &b){
	std::cout << "Copy Constuctor called (Brain)" << std::endl;
	*this = b;
}

Brain::~Brain(){
	std::cout << "Destuctor called (Brain)" << std::endl;
}

Brain &Brain::operator=(const Brain &b){
	if (this != &b)	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = b._ideas[i];
	}
	return *this;
}
