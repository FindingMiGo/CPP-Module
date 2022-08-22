#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a;
    ClapTrap b("b");
    ClapTrap c(b);
    
    std::cout << std::endl;
    a.attack("b");
    b.takeDamage(a.getAttackDamege());
    std::cout <<std::endl;
    b.beRepaired(3);
    b.takeDamage(10);
    b.takeDamage(3);
    std::cout <<std::endl;
    b.attack("a");
    b.beRepaired(3);
    b.takeDamage(1);
    std::cout << std::endl;
}
