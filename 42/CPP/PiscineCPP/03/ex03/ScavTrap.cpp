#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name)
{
	setHitpoints(init_hit_points_);
	setEnergy(init_energy_points_);
	setDamage(init_attack_damage_);
	this->_name = name;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src)
{
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energy_points = src._hitpoints;
	this->_attack_damage = src._attack_damage;
	std::cout << "ScavTrap " << this->_name << " has been copied" << std::endl;
}

ScavTrap::ScavTrap():_name("Default_Scavtrap")
{
	setHitpoints(init_hit_points_);
	setEnergy(init_energy_points_);
	setDamage(init_attack_damage_);
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
		std::cout << this->_name << " deals " << getDamage() << " to " << target << std::endl;
		setEnergy(--energy);
	}
	else
	{
		std::cout << this->_name << "could not attack because it had no more energy !" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << this->_name << " has entered guard mode" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */