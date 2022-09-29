#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	{
		std::cout << "=====Animal array test=====\n";
		Animal* a[10];
		for (int i = 0;i < 10; i++){
			if (i < 5){
				a[i] = new Dog();
			}
			else{
				a[i] = new Cat();
			}
		}
		for (int i = 0;i < 10; i++){
			delete a[i];
		}
	}
	{
		std::cout << "\n\n=====Brain copy test=====\n";
		Cat *c = new Cat();
		Cat c2(*c);

		c->printBrain();
		delete c;
		c2.printBrain();
	}
}
