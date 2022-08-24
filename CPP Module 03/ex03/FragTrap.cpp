#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &ft):ClapTrap(ft){}

FragTrap::~FragTrap(){}

FragTrap &FragTrap::operator=(const FragTrap &ft){
	if (this != &ft)	{
		_name = ft._name;
		_hitPoints = ft._hitPoints;
		_energyPoints = ft._energyPoints;
		_attackDamage = ft._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void){
    std::cout<< "FragTrap "<< _name << " positive high fives request"<<std::endl;
}
