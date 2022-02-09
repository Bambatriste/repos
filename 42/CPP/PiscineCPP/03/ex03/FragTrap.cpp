#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name)
{
	setHitpoints(init_hit_points_);
	setEnergy(init_energy_points_);
	setDamage(init_attack_damage_);
	this->_name = name;
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energy_points = src._hitpoints;
	this->_attack_damage = src._attack_damage;
	std::cout << "FragTrap " << this->_name << " has been copied" << std::endl;
}

FragTrap::FragTrap():_name("Default_Fragtrap")
{
	setHitpoints(init_hit_points_);
	setEnergy(init_energy_points_);
	setDamage(init_attack_damage_);
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
		std::cout << this->_name << " deals " << getDamage() << " to " << target << std::endl;
		setEnergy(--energy);
	}
	else
	{
		std::cout << this->_name << " could not attack because it had no more energy !" << std::endl;
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