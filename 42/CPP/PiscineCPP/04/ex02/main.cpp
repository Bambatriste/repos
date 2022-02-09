#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal	*Pets[20];

	for (int i = 0; i < 10; i++)
		Pets[i] = new Dog();
	for (int i = 10; i < 20; i++)
		Pets[i] = new Cat();
	for (int i = 0; i < 20; i++)
		delete Pets[i];

	Dog dog1;
	Dog dog2(dog1); //deep copy
	Dog dog3 = dog2; //shallow copy

	std::cout << dog1.getBrain()->ideas[0] << std::endl;
	std::cout << dog1.getBrain()->ideas[1] << std::endl;

	std::cout << dog2.getBrain()->ideas[2] << std::endl;
	std::cout << dog2.getBrain()->ideas[3] << std::endl;

	std::cout << dog3.getBrain()->ideas[4] << std::endl;
	std::cout << dog3.getBrain()->ideas[5] << std::endl;

	Cat cat1;
	Cat cat2(cat1);
	Cat cat3 = cat2;

	std::cout << cat1.getBrain()->ideas[0] << std::endl;
	std::cout << cat1.getBrain()->ideas[1] << std::endl;

	std::cout << cat2.getBrain()->ideas[2] << std::endl;
	std::cout << cat2.getBrain()->ideas[3] << std::endl;

	std::cout << cat3.getBrain()->ideas[4] << std::endl;
	std::cout << cat3.getBrain()->ideas[5] << std::endl;

	//Animal bob;
	// doesn t compile because makesound is pure virtual



	return (0);
}