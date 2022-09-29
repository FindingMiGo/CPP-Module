#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat:public Animal{
	private:
		Brain *brain_;
	public:
		Cat();
		Cat(const Cat &Cat);
		Cat(const std::string &str);
		~Cat();
		Cat &operator=(const Cat &Cat);
		void makeSound()const;
		void printBrain()const;
};

#endif
