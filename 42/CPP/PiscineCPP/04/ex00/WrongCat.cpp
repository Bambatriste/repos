#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	WrongAnimal::type = "WrongCat";
	std::cout << "A Wrongcat has been created by default constructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	type = src.type;
	*this = src;
	std::cout << "A Wrongcat has been created by copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &WrongCat::operator=( WrongCat const & rhs )
{
	type = rhs.type;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound() const
{
	std::cout << "Meowwwww RrRrRrRr" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */