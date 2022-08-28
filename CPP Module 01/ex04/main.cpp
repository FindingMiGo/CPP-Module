#include "Sed.hpp"

int main(int ac, char **av){
	if (ac != 4)
		return (0);
	if (av[2][0] == '\0' || av[3][0] == '\0')
		return (0);
	Sed sed(av[1], av[2], av[3]);
	sed.replaceStr();
	return (0);
}
