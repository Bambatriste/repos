#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed:" << std::endl;
}

void
	Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void
	Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string
	Zombie::get_name(void) const
{
	return (this->_name);
}
