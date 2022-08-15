#include "Zombie.hpp"

#define NUM 5

int	main()
{
	Zombie *zombie;

	zombie = zombieHorde(NUM, "Shane");
	for (int i = 0; i < NUM; i++)
		zombie[i].announce();
	std::cout << std::endl;
	delete[] zombie;
	return (0);
}
