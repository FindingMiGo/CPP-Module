#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(){
	type = "WrongCat";
	std::cout << "Constructor called (WrongCat)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc):WrongAnimal(){
	*this = wc;
	std::cout << "Copy constructor called (WrongCat)" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "Destructor called (WrongCat)" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wc){
	if(this != &wc)
		type = wc.type;
	return *this;
}

void WrongCat::makeSound()const{
	std::cout << "I am a cat" << std::endl;
}
