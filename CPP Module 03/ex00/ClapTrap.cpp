#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	_name = "JohnDoe";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Default constructor called ("<< _name << ")"<< std::endl;
}

ClapTrap::ClapTrap(std::string name){
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "String constructor called ("<< _name << ")"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct){
	*this = ct;
	std::cout << "Copy Constructor called ("<< _name << ")" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called ("<< _name << ")" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct){
	if (this != &ct)	{
		_name = ct._name;
		_hitPoints = ct._hitPoints;
		_energyPoints = ct._energyPoints;
		_attackDamage = ct._attackDamage;
	}
	std::cout << "Assignment operator called ("<< _name << ")" << std::endl;
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	if (_energyPoints == 0){
		std::cout << "Not enough energypoints" << std::endl;
		return ;
	}
	if (_hitPoints == 0){
		std::cout << "ClapTrap " << _name << " is no reply. It's just corpse." << std::endl;
		return ;
	}
	std::cout 
	<< "ClapTrap " << _name << " attacks " << target 
	<< ", causing " << _attackDamage << " points of damage!" 
	<< std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is no reply. It's just corpse." << std::endl;
	else if (_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints == 0){
		std::cout << "Not enough energypoints" << std::endl;
		return ;
	}
	if(_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is no reply. It's just corpse." << std::endl;
	else
	{
		std::cout <<"ClapTrap "<< _name << " recovered " << amount << " points!" << std::endl;
		_hitPoints += amount;
	}
	_energyPoints--;
}

unsigned int  ClapTrap::getAttackDamege(){
	return(_attackDamage);
}
