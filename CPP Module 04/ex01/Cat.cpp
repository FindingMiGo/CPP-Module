#include "Cat.hpp"

Cat::Cat():Animal(){
	type = "Cat";
	brain_ = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat):Animal(){
	brain_ = new Brain();
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::Cat(const std::string &str):Animal(){
	type = "Cat";
	brain_ = new Brain(str);
	std::cout << "Cat string constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain_;
}

Cat &Cat::operator=(const Cat &cat){
	if(this != &cat){
		delete brain_;
		type = cat.type;
		brain_ = new Brain(*cat.brain_);
	}
	return *this;
}

void Cat::makeSound()const{
	std::cout << "Meow" << std::endl;
}

void Cat::printBrain()const{
	brain_->printIdeas();
}
