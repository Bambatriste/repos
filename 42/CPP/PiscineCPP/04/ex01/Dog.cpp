#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	type = "Dog";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		if (i %2)
			_brain->ideas[i] = "i like food";
		else
			_brain->ideas[i] = "i like hoomans";
	}
	std::cout << "A dog has been created" << std::endl;
}

Dog::Dog(const Dog&src)
{
	type = src.type;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		_brain->ideas[i] = src._brain->ideas[i];
	}
	std::cout << "A dog has been created by copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete _brain;
	std::cout << "A dog has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog	&Dog::operator=(Dog const &rhs)
{
	if ( this != &rhs )
	{
		this->type =  rhs.type;
		_brain = rhs._brain;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Dog::getBrain() const
{
	return _brain;
}


/* ************************************************************************** */