#include "Cat.hpp"

Cat::Cat():Animal(){
	type = "Cat";
	std::cout << "Constructor called (Cat)" << std::endl;
}

Cat::Cat(const Cat &cat):Animal(){
    *this = cat;
    std::cout << "Copy constructor called (Cat)" << std::endl;
}

Cat::~Cat(){
    std::cout << "Destructor called (Cat)" << std::endl;
}

Cat &Cat::operator=(const Cat &cat){
    if(this != &cat)
        type = cat.type;
    return *this;
}

void Cat::makeSound()const{
    std::cout << "Meow" << std::endl;
}
