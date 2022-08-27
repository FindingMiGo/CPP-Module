#include "Dog.hpp"

Dog::Dog():Animal(){
	type = "Dog";
	std::cout << "Constructor called (Dog)" << std::endl;
}

Dog::Dog(const Dog &dog):Animal(){
    *this = dog;
    std::cout << "Copy constructor called (Dog)" << std::endl;
}

Dog::~Dog(){
    std::cout << "Destructor called (Dog)" << std::endl;
}

Dog &Dog::operator=(const Dog &dog){
    std::cout << "Assigned Operator called (Dog)" << std::endl;
    if(this != &dog)
        type = dog.type;
    return *this;
}

void Dog::makeSound()const{
    std::cout << "Bow" << std::endl;
}
