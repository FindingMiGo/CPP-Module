#include "Zombie.hpp"

int	main()
{
	Zombie *steve = newZombie("Steve");
	Zombie tony = Zombie("Tony");

    steve->announce();
    delete steve;
	randomChump("Strange");
	tony.announce();
	return (0);
}
