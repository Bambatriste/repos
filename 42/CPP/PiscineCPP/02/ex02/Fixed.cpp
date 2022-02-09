#include "Fixed.hpp"
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(int const n)
{
	this->_value = n << 8;
}

Fixed::Fixed(float const f)
{
	this->_value = roundf(f * (1 << Fixed::_fractional));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(void)
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed	&Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs)const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs)const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs)const
{
	Fixed r;
	r.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (r);
}

Fixed
	Fixed::operator-(Fixed const &rhs)const
{
	Fixed r;
	r.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (r);
}

Fixed
	Fixed::operator*(Fixed const &rhs)const
{
	Fixed r;
	r.setRawBits((this->getRawBits() * rhs.getRawBits()) >> Fixed::_fractional);
	return (r);
}

Fixed
	Fixed::operator/(Fixed const &rhs)const
{
	Fixed r;
	r.setRawBits(this->getRawBits() / (rhs.getRawBits() >> Fixed::_fractional));
	return (r);
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed old = *this;
	this->_value++;
	return (old);
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed old = *this;
	this->_value--;
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
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