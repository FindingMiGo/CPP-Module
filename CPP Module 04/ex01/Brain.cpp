#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constuctor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas_[i] = "string";
}

Brain::Brain(const std::string &str){
	std::cout << "Brain string constuctor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas_[i] = str;
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
			ideas_[i] = b.ideas_[i];
	}
	return *this;
}

void Brain::printIdeas(){
	std::cout << ideas_ << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ideas_[i] << " ";
	std::cout << std::endl;
}
