#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain_;
	public:
		Dog();
		Dog(const Dog &Dog);
		Dog(const std::string &str);
		~Dog();
		Dog &operator=(const Dog &Dog);
		void makeSound()const;
		void printBrain()const;
};

#endif
