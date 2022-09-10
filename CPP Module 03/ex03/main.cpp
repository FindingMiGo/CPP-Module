#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "===constructor test===\n\n";
	{
		DiamondTrap a;
		DiamondTrap b("b");
		DiamondTrap c(b);
	}
	std::cout << "\n===whoami test===\n\n";
	{
		DiamondTrap a;
		DiamondTrap b("b");
		DiamondTrap c(b);

		a.whoAmI();
		b.whoAmI();
		c.whoAmI();
	}
	std::cout << "\n===attack and takeDamage test===\n\n";
	{
		DiamondTrap a("Brave");
		DiamondTrap b("Devil");

		std::cout << std::endl;
		a.beRepaired(10);
		a.attack("Devil");
		b.takeDamage(a.getAttackDamege());
		b.attack("Brave");
		a.takeDamage(100);
		a.attack("Devil");
		a.beRepaired(10);
	}
	std::cout << "\n===highFivesGuys  guardGate test===\n\n";
	{
		DiamondTrap a("Brave");

		std::cout << std::endl;
		a.highFivesGuys();
		a.guardGate();
		std::cout << std::endl;
	}
	return (0);
}
