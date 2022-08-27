#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	type = "WrongAnimal";
	std::cout << "Constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa){
	*this = wa;
	std::cout << "Copy constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Destructor called (WrongAnimal)" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa){
	if(this != &wa)
		type = wa.type;
	return *this;
}

void WrongAnimal::makeSound()const{
    std::cout << "Hi" << std::endl;
}
