#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(std::string name)
:
ClapTrap(name),
FragTrap(name),
ScavTrap(name),
_name(name)
{
	ClapTrap::setName(name + "_clap_name");
	setHitpoints(FragTrap::init_hit_points_);
	setEnergy(ScavTrap::init_energy_points_);
	setDamage(FragTrap::init_attack_damage_);
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
:
ClapTrap(src._name),
FragTrap(src._name),
ScavTrap(src._name),
_name(src._name)
{
	ClapTrap::setName(_name + "_clap_name");
	setHitpoints(src._hitpoints);
	setEnergy(src._energy_points);
	setDamage(src._attack_damage);
	std::cout << "DiamondTrap " << this->_name << " has been copied" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	DiamondTrap::attack(std::string const &target)
{
	this->FragTrap::attack(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << " and my grandfather name is " << ClapTrap::getName() << std::endl;
}


/* ************************************************************************** */