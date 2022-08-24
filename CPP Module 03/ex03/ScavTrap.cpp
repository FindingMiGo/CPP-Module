#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap():ClapTrap(){}

ScavTrap::ScavTrap(std::string name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap(){}

ScavTrap::ScavTrap(const ScavTrap &st):ClapTrap(st){}

ScavTrap &ScavTrap::operator=(const ScavTrap &st){
    if(this != &st){
        _name = st._name;
        _hitPoints = st._hitPoints;
        _energyPoints = st._energyPoints;
        _attackDamage = st._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const &target){
	if (_energyPoints == 0){
		std::cout << "no energypoints" << std::endl;
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
		std::cout << "no energypoints" << std::endl;
		return ;
	}
	if (_hitPoints == 0){
		std::cout << "ScavTrap " << _name << " is no reply. It's just corpse." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
}
