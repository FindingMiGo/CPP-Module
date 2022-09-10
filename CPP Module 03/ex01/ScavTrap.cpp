#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called ("<< _name << ")"<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap string constructor called ("<< _name << ")"<< std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called ("<< _name << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st){
	std::cout << "ScavTrap copy Constructor called ("<< _name << ")" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st){
    if(this != &st){
        _name = st._name;
        _hitPoints = st._hitPoints;
        _energyPoints = st._energyPoints;
        _attackDamage = st._attackDamage;
    }
	std::cout << "ScavTrap assignment operator called ("<< _name << ")" << std::endl;
    return *this;
}

void ScavTrap::attack(std::string const &target){
	if (_energyPoints == 0){
		std::cout << "Not enough energypoints" << std::endl;
		return ;
	}
	if (_hitPoints == 0){
		std::cout << "ScavTrap " << _name << " is no reply. It's just corpse." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate(){
	if (_energyPoints == 0){
		std::cout << "Not enough energypoints" << std::endl;
		return ;
	}
	if (_hitPoints == 0){
		std::cout << "ScavTrap " << _name << " is no reply. It's just corpse." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
