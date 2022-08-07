#include <iostream>
#include <string>

std::string capitalizer(std::string s)
{
	for(size_t i = 0; i < s.size(); i++)
		s[i] = std::toupper(s[i]);
	return (s);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << capitalizer(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}
