#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{	
	const Animal* animal[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		animal[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete animal[i];
	Dog basic;
	{
		Dog tmp = basic;
	}
	Cat basic2;
	{
		Cat tmp = basic2;
	}
}
