#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	{
		std::cout << "===Sample Tests===\n";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << "===Wrong Animal Tests===\n";
		const WrongAnimal* i = new WrongAnimal();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << "===Wrong Cat Tests===\n";
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << "===All member function Tests===\n";
		Animal *a = new Animal();
		Animal *c = new Cat();
		Animal *d = new Dog();
		WrongAnimal *wa = new WrongAnimal();
		WrongAnimal *wc = new WrongCat;

		std::cout << a->getType() << std::endl;
		a->makeSound();
		std::cout << c->getType() << std::endl;
		c->makeSound();
		std::cout << d->getType() << std::endl;
		d->makeSound();
		std::cout << wa->getType() << std::endl;
		wa->makeSound();
		std::cout << wc->getType() << std::endl;
		wc->makeSound();
		delete a;
		delete c;
		delete d;
		delete wa;
		delete wc;
	}
}
