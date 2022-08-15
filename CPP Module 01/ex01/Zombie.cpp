#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie(void)
{
    std::cout<< this->_name << this->num;
    std::cout<< " was minced."<<std::endl;
}

void    Zombie::announce(void)
{
    std::cout<< this->_name << this->num << ": ";
    std::cout<< "BraiiiiiiinnnzzzZ..."<<std::endl; 
}

void Zombie::setName(std::string name)
{
    _name = name;
}

void Zombie::setNum(int i)
{
    num = i;
}
