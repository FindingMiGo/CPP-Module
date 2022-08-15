#include "Zombie.hpp"
#include <cstdlib>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombie;

    try{
        zombie = new Zombie[N];
    }catch (...){
        std::cout << "error" << std::endl;
        exit(1);
    }
    for (int i = 0; i < N; i++)
    {
        zombie[i].setNum(i);
        zombie[i].setName(name);
    }
    return (zombie);
}
