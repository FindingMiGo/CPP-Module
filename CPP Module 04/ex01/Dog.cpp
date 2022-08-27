#include "Dog.hpp"

Dog::Dog():Animal(){
	type = "Dog";
	_brain = new Brain();
	std::cout << "Constructor called (Dog)" << std::endl;
}

Dog::Dog(const Dog &dog):Animal(){
	_brain = new Brain();
	*this = dog;
	std::cout << "Copy constructor called (Dog)" << std::endl;
}

Dog::~Dog(){
	std::cout << "Destructor called (Dog)" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &dog){
	if(this != &dog){
		delete _brain;
		type = dog.getType();
		_brain = new Brain(*dog._brain);
	}
	return *this;
}

void Dog::makeSound()const{
	std::cout << "Bow" << std::endl;
}
