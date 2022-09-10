#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called ("<< _name << ")"<< std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap string constructor called ("<< _name << ")"<< std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft){
	std::cout << "FragTrap copy Constructor called ("<< _name << ")" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called ("<< _name << ")" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft){
	if (this != &ft){
		_name = ft._name;
		_hitPoints = ft._hitPoints;
		_energyPoints = ft._energyPoints;
		_attackDamage = ft._attackDamage;
	}
	std::cout << "FragTrap assignment operator called ("<< _name << ")" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void){
    std::cout<< "FragTrap "<< _name << " \"HIGH FIVE!\""<<std::endl;
}
