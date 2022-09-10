#include "ClapTrap.hpp"

int main( void ) {
	std::cout << "===constructor test===\n\n";
	{
		ClapTrap a;
		ClapTrap b("b");
		ClapTrap c(b);
	}
	std::cout << "\n===attack and takeDamage test===\n\n";
	{
		ClapTrap a("Brave");
		ClapTrap b("Devil");
		std::cout << std::endl;
		a.attack("Devil");
		b.takeDamage(a.getAttackDamege());
		b.attack("Brave");
		a.takeDamage(10);
		a.attack("Devil");
		a.beRepaired(10);
		for (int i = 0; i < 10; i++)
			b.attack("Brave");
	}
	std::cout << "\n===beRepaired test===\n\n";
	{
		ClapTrap a("Brave");

		for (int i = 0; i < 10; i++)
			a.beRepaired(10);
		a.beRepaired(10);
	}
}
