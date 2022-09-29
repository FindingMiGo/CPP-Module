#include "Dog.hpp"

Dog::Dog():Animal(){
	type = "Dog";
	brain_ = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog):Animal(){
	brain_ = new Brain();
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete brain_;
}

Dog &Dog::operator=(const Dog &dog){
	if(this != &dog){
		delete brain_;
		type = dog.type;
		brain_ = new Brain(*dog.brain_);
	}
	return *this;
}

void Dog::makeSound()const{
	std::cout << "Bow" << std::endl;
}
