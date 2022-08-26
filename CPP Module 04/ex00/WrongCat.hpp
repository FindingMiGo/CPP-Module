#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal{
	protected:
		std::string type;
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &wc);
		WrongCat &operator=(const WrongCat &wc);
		std::string getType()const;
		void makeSound() const;
};

#endif
