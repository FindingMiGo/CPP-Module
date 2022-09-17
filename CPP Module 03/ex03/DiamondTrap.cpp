#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	_name = "JohnDoe";
	ClapTrap::_name = "JohnDoe_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called ("<< _name << ")"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name){
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap string constructor called ("<< _name << ")"<< std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called ("<< _name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(), ScavTrap(), FragTrap(){
	_name = dt._name;
	ClapTrap::_name = dt._name + "_clap_name";
	FragTrap::_hitPoints = dt._hitPoints;
	ScavTrap::_energyPoints = dt._energyPoints;
	FragTrap::_attackDamage = dt._attackDamage;
	std::cout << "DiamondTrap copy Constructor called ("<< _name << ")" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt)
{
	if (this != &dt)
	{
		_name = dt._name;
		ClapTrap::_name = dt._name + "_clap_name";
		FragTrap::_hitPoints = dt._hitPoints;
		ScavTrap::_energyPoints = dt._energyPoints;
		FragTrap::_attackDamage = dt._attackDamage;
	}
	std::cout << "DiamondTrap assignment operator called ("<< _name << ")" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap name\t: " << _name <<std::endl;
	std::cout << "ClapTrap name\t\t: " << ClapTrap::_name <<std::endl;
}

void DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}
