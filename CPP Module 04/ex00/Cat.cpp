#include "Cat.hpp"

Cat::Cat():Animal(){
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat):Animal(){
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat){
	if(this != &cat)
		type = cat.type;
	return *this;
}

void Cat::makeSound()const{
	std::cout << "Meow" << std::endl;
}
