#include "Phonebook.hpp"

void	printHedder()
{
	std::cout << "|" << std::setw(10) << std::right << "INDEX";
	std::cout << "|" << std::setw(10) << std::right << "FIRST NAME";
	std::cout << "|" << std::setw(10) << std::right << "LAST NAME";
	std::cout << "|" << std::setw(10) << std::right << "NICK NAME";
	std::cout << "|" << std::endl;
}

bool	isValidStr(std::string str)
{
	if (str == "" || str.size() != 1)
		return (false);
	if (str[0] >= '1' && str[0] <= '8')
		return (true);
	return (false);
}

phonebook::phonebook()
{
	num = 0;
}

void	phonebook::add()
{
	std::cout << "INPUT DATA" << std::endl;
	if (contactlist[num].insert() == false)
		return ;
	num++;
	if (num >= 8)
		num = 0;
	return ;
}

void	phonebook::search()
{
	std::string input;
	int	num;

	if (!contactlist[0].isInputed())
	{
		std::cout << "NO DATA" << std::endl;
		return ;
	}
	printHedder();
	for (int i = 0; i < 8; i++)
	{
		if (!contactlist[i].isInputed())
			break ;
		contactlist[i].printIndex(i);
	}
	std::cout << "CHOOSE A NUMBER (1 ~ 8)" << std::endl;
	while(!std::cin.eof())
	{
		std::getline(std::cin, input);
		num = atoi(input.c_str());
		if (!isValidStr(input))
		{
			std::cout << "INCOMPLETE INPUT" << std::endl;
			break ;
		}
		else if (num > 0 && num < 9)
			contactlist[num - 1].printData();
		else
		{
			std::cout << "NO DATA" << std::endl;
			break ;
		}
	}
	return ;
}

void	phonebook::repl()
{
	std::string	input;

	while(!std::cin.eof())
	{
		std::cout << "ENTER COMMAND (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			break;
	}
}

int	main()
{
	phonebook	pb;
	pb.repl();
	return (0);
}
