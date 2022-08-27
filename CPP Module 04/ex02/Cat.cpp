#include "Cat.hpp"

Cat::Cat():Animal(){
	type = "Cat";
    _brain = new Brain();
	std::cout << "Constructor called (Cat)" << std::endl;
}

Cat::Cat(const Cat &Cat):Animal(){
    _brain = new Brain();
    *this = Cat;
    std::cout << "Copy constructor called (Cat)" << std::endl;
}

Cat::~Cat(){
    delete _brain;
    std::cout << "Destructor called (Cat)" << std::endl;
}

Cat &Cat::operator=(const Cat &Cat){
    if(this != &Cat){
        delete _brain;
        type = Cat.getType();
        _brain = new Brain(*Cat._brain);
    }
    return *this;
}

void Cat::makeSound()const{
    std::cout << "Meow" << std::endl;
}
