#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie()
{
	std::cout << get_name() << " has been destroyed" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

std::string Zombie::get_name(void)
{
	return (this->name);
}

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
