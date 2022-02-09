#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name)
:
ClapTrap(name),
_name(name)
{
	setHitpoints(100);
	setEnergy(50);
	setDamage(20);
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap()
:
ClapTrap("ScavTrap"),
_name("ScavTrap")
{
	setHitpoints(100);
	setEnergy(50);
	setDamage(20);
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src)
:
ClapTrap(src._name),
_name(src._name)
{
	setHitpoints(src._hitpoints);
	setEnergy(src._energy_points);
	setDamage(src._attack_damage);
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const std::string &target)
{
	if (getEnergy() > 0)
	{
		unsigned int energy = getEnergy();
		std::cout << this->_name << " the ScavTrap deals " << getDamage() << " to " << target << std::endl;
		setEnergy(--energy);
	}
	else
	{
		std::cout << this->_name << " The ScavTrap could not attack because it had no more energy !" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << this->_name << " The Scavtrap has entered guard mode" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */