#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &wa);
		WrongAnimal &operator=(const WrongAnimal &wa);
		std::string getType()const;
		virtual void makeSound() const;
};

#endif
