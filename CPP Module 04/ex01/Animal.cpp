#include "Animal.hpp"

Animal::Animal(){
	type = "none";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal){
    *this = animal;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal){
    if(this != &animal)
        type = animal.type;
    return *this;
}

std::string Animal::getType()const{
    return type;
}

void Animal::makeSound()const{
    std::cout << " " << std::endl;
}
