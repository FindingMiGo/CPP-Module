#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(){
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc):WrongAnimal(){
	*this = wc;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wc){
	if(this != &wc)
		type = wc.type;
	return *this;
}

void WrongCat::makeSound()const{
	std::cout << "I am a cat" << std::endl;
}
