#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		ScavTrap();
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &rhs);
		void guardGate();
		void attack(const std::string &target);
	protected:
		std::string _name;
		static const unsigned int init_hit_points_ = 100;
    	static const unsigned int init_energy_points_ = 50;
    	static const unsigned int init_attack_damage_ = 20;

};

#endif /* ******************************************************** SCAVTRAP_H */