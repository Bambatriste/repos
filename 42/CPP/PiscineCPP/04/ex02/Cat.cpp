#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	Animal::type = "Cat";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		if (i %2)
			_brain->ideas[i] = "i like to sleep";
		else
			_brain->ideas[i] = "when are my slaves bringing me food?";
	}
	std::cout << "A cat has been created by default constructor" << std::endl;
}

Cat::Cat(const Cat &src)
{
	type = src.type;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		_brain->ideas[i] = src._brain->ideas[i];
	}
	std::cout << "A cat has been created by copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete _brain;
	std::cout << "A cat has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=( Cat const & rhs )
{
	type = rhs.type;
	_brain = rhs._brain;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound() const
{
	std::cout << "Meowwwww RrRrRrRr" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Cat::getBrain() const
{
	return _brain;
}

/* ************************************************************************** */