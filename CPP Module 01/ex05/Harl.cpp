#include "Harl.hpp"

Harl::Harl(){
    _func[0] = &Harl::debug;
    _func[1] = &Harl::info;
    _func[2] = &Harl::warning;
    _func[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug(){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
	int	index =	(level == "debug")		|
				(level == "info") * 2	|
				(level == "warning") * 3|
				(level == "error") * 4;
	if (index > 4 || index < 1)
		return ;
	(this->*_func[index - 1])();
}
