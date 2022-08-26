#include "Dog.hpp"

Dog::Dog():Animal(){
	type = "Dog";
    _brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog):Animal(){
    _brain = new Brain();
    *this = dog;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog &Dog::operator=(const Dog &dog){
    std::cout << "Assigned operator called (Dog)" << std::endl;
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
