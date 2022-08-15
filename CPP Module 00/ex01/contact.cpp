#include "contact.hpp"

std::string	trimStr(std::string str)
{
	if (str.length() > 10)
		str = str.replace(9, 1 , ".").substr(0, 10);
	return (str);
}

bool	isBlank(std::string str[5])
{
	size_t	j;

	for (int i = 0; i < 5; i++)
	{
		if (str[i] == "")
			return (true);
		for (j = 0; j < str[i].size(); j++)
		{
			if (str[i][j] != ' ' && str[i][j] != '	')
				break ;
		}
		if (str[i].size() == j)
			return (true);
	}
	return (false);
}

void	Contact::printIndex(int i)
{
	std::cout << "|" << std::setw(10) << std::right << (char)(i + 1 + '0');
	std::cout << "|" << std::setw(10) << std::right << trimStr(first_name);
	std::cout << "|" << std::setw(10) << std::right << trimStr(last_name);
	std::cout << "|" << std::setw(10) << std::right << trimStr(nickname) << "|" << std::endl;
}

bool	Contact::isInputed()
{
	if (first_name == "")
		return (false);
	return (true);
}

std::string Contact::inputStr(std::string msg)
{
	std::string	input;

	std::cout << msg << ':';
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "Input interrupted." << std::endl;
		exit(1);
	}
	else
		return (input);
}

void	Contact::printData()
{
	if (first_name == "")
	{
		std::cout << "NO DATA" << std::endl;
		return ;
	}
	std::cout << std::setw(14) << std::left << "first name" << ":" << first_name << std::endl;
	std::cout << std::setw(14) << std::left << "last name" << ":" << last_name << std::endl;
	std::cout << std::setw(14) << std::left << "nickname" << ":" << nickname << std::endl;
	std::cout << std::setw(14) << std::left << "phone number" << ":" << phone_number << std::endl;
	std::cout << std::setw(14) << std::left << "darkest secret" << ":" << darkest_secret << std::endl;
}

bool	Contact::insert()
{
	std::string	tmp[5];

	tmp[0] = inputStr("first name");
	tmp[1] = inputStr("last name");
	tmp[2] = inputStr("nickname");
	tmp[3] = inputStr("phone number");
	tmp[4] = inputStr("darkest secret");
	if (isBlank(tmp))
	{
		std::cout << "INCOMPLETE INPUT" << std::endl;
		return (false);
	}
	else
	{
		first_name = tmp[0];
		last_name = tmp[1];
		nickname = tmp[2];
		phone_number = tmp[3];
		darkest_secret = tmp[4];
	}
	return (true);
}

