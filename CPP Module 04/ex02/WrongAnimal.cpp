#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa){
	*this = wa;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa){
	if(this != &wa)
		type = wa.type;
	return *this;
}

std::string WrongAnimal::getType() const{
	return type;
}

void WrongAnimal::makeSound()const{
	std::cout << "Hi" << std::endl;
}
