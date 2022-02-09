#include "Fixed.hpp"
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << 8;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << Fixed::_fractional));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed			&Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Fixed::setRawBits(int raw)
{
	this->_value = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_value) / ( 1 << Fixed::_fractional));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fractional);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */