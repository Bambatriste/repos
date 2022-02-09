#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name)
:
ClapTrap(name),
_name(name)
{
	setHitpoints(100);
	setEnergy(100);
	setDamage(30);
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap()
:
ClapTrap(),
_name("FragTrap")
{
	setHitpoints(100);
	setEnergy(100);
	setDamage(30);
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
:
ClapTrap(src._name),
_name(src._name)
{
	setHitpoints(src._hitpoints);
	setEnergy(src._energy_points);
	setDamage(src._attack_damage);
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void FragTrap::attack(const std::string &target)
{
	if (getEnergy() > 0)
	{
		unsigned int energy = getEnergy();
		std::cout << this->_name << " the FragTrap deals " << getDamage() << " to " << target << std::endl;
		setEnergy(--energy);
	}
	else
	{
		std::cout << this->_name << " The FragTrap could not attack because it had no more energy !" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " raises his hand and yells: 'HIGH FIVE GUYS !!'" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */