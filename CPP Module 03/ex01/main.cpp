#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "===constructor test===\n\n";
	{
		ScavTrap a;
		ScavTrap b("b");
		ScavTrap c(b);
	}
	std::cout << "\n===attack and takeDamage test===\n\n";
	{
		ScavTrap a("Brave");
		ScavTrap b("Devil");
		std::cout << std::endl;
		a.attack("Devil");
		b.takeDamage(a.getAttackDamege());
		b.attack("Brave");
		a.takeDamage(100);
		a.attack("Devil");
		a.beRepaired(10);
	}
	std::cout << "\n===guardGate test===\n\n";
	{
		ScavTrap a("Brave");
		a.guardGate();
	}
}
