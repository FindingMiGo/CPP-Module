#include "Animal.hpp"

Animal::Animal(){
	type = "Animal";
	std::cout << "Constructor called (Animal)" << std::endl;
}

Animal::Animal(const Animal &animal){
    *this = animal;
    std::cout << "Copy constructor called (Animal)" << std::endl;
}

Animal::~Animal(){
    std::cout << "Destructor called (Animal)" << std::endl;
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
    std::cout << "Animal makeSound() Called" << std::endl;
}
