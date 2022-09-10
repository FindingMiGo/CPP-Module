#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	std::cout << "===constructor test===\n\n";
	{
		FragTrap a;
		FragTrap b(a);
		FragTrap c("c");
	}
	std::cout << "\n===attack and takeDamage test===\n\n";
	{
		FragTrap a("Brave");
		FragTrap b("Devil");
		std::cout << std::endl;
		a.attack("Devil");
		b.takeDamage(a.getAttackDamege());
		b.attack("Brave");
		a.takeDamage(100);
		a.attack("Devil");
		a.beRepaired(10);
	}
	std::cout << "\n===highFivesGuys test===\n\n";
	{
		FragTrap a("Brave");
		a.highFivesGuys();
	}
}
