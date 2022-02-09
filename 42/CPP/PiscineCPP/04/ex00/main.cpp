#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	

	std::cout << j->getType() << " : ";
	j->makeSound(); //dog sound
	std::cout << i->getType() << " : ";
	i->makeSound(); //will output the cat sound!
	
	meta->makeSound();
 
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << std::endl << std::endl;

	const WrongAnimal *y = new WrongAnimal();
	const WrongAnimal *z = new WrongCat();

	std::cout << z->getType() << " " << std::endl;
	y->makeSound();
	z->makeSound();// makes animal sound because this time makeSound isn t virtual

	delete y;
	delete z;

	return (0);
}