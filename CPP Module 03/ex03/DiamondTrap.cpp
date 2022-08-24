#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(){
	_name = "dia";
	ClapTrap::_name = "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(), ScavTrap(), FragTrap(){
	_name = "dia";
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap(){}

DiamondTrap::DiamondTrap(const DiamondTrap &dt):ClapTrap(), ScavTrap(), FragTrap(){
	_name = dt._name;
	ClapTrap::_name = dt._name + "_clap_name";
	FragTrap::_hitPoints = dt._hitPoints;
	ScavTrap::_energyPoints = dt._energyPoints;
	FragTrap::_attackDamage = dt._attackDamage;
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
	return *this;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap name\t" << _name <<std::endl;
    std::cout << "ClapTrap name\t" << ClapTrap::_name <<std::endl;
}

void DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}
