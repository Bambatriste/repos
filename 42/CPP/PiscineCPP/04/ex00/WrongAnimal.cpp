#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	std::cout << "an WrongAnimal was created by default constructor" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	type = src.type;
	*this = src;
	std::cout << "an WrongAnimal was created by copy constructor" << std::endl; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "an WrongAnimal was destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongAnimal::makeSound() const
{
	std::cout << "A random animal sound " << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string  WrongAnimal::getType() const
{
	return (this->type);

}


/* ************************************************************************** */