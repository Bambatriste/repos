#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();
		FragTrap();
		FragTrap &operator=( FragTrap const & rhs );
		void	attack(std::string const & target);
		void	highFivesGuys(void);
	protected:
		std::string _name;
    	static const unsigned int init_hit_points_ = 100;
    	static const unsigned int init_energy_points_ = 100;
    	static const unsigned int init_attack_damage_ = 30;
};

#endif /* ******************************************************** FRAGTRAP_H */