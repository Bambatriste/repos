#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name):_name(name), _hitpoints(10), _attack_damage(0), _energy_points(10)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap():_name("ClapTrap"), _hitpoints(10), _attack_damage(0), _energy_points(10)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{

	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_attack_damage = rhs._attack_damage;
	_energy_points = rhs._energy_points;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ClapTrap const &i)
{
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << this->_name << " deals " << this->_attack_damage << " to " << target << std::endl;
		this->_energy_points--;
	}
	else
	{
		std::cout << this->_name << " could not attack because it had no more energy !" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= amount)
	{
		std::cout << this->_name << " takes " << _hitpoints << " damages, he is at death's door !" << std::endl;
		this->_hitpoints = 0;
	}
	else
	{
		this->_hitpoints -= amount;
		std::cout << this->_name << " takes " << amount << " damages" << std::endl;
	}
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		std::cout << this->_name << " repairs himself for an amount of " << amount << " hitpoints" << std::endl;
		this->_energy_points--;
		this->_hitpoints += amount;
	}
	else
	{
		std::cout << this->_name << " could not repair itself because it had no more energy !" << std::endl;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
		void 			ClapTrap::setDamage(unsigned int damage_value)
		{
			this->_attack_damage = damage_value;
		}
		unsigned int  	ClapTrap::getDamage()
		{
			return (this->_attack_damage);
		}
		void 			ClapTrap::setHitpoints(unsigned int hitpoints_value)
		{
			this->_hitpoints = hitpoints_value;
		}
		unsigned int	ClapTrap::getHitpoints()
		{
			return(this->_hitpoints);
		}
		void 			ClapTrap::setEnergy(unsigned int energy_value)
		{
			this->_energy_points = energy_value;
		}
		unsigned int	ClapTrap::getEnergy()
		{
			return (this->_energy_points);
		}
		void 			ClapTrap::setName(std::string name)
		{
			this->_name = name;
		}
		std::string		ClapTrap::getName()
		{
			return (this->_name);
		}


/* ************************************************************************** */