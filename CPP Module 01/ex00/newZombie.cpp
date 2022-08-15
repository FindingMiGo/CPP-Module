#include "Zombie.hpp"
#include <cstdlib>

Zombie *newZombie(std::string name)
{
	Zombie *zombie;

	try{
		zombie = new Zombie(name);
	} catch (...){
		std::cout << "error" << std::endl;
		exit(1);
	}
	return (zombie);
}
