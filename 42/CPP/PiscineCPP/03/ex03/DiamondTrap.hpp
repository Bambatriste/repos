#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  virtual public FragTrap ,virtual public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &rhs);
		void	attack(std::string const &target);
		void	whoAmI(void);

	private:
		std::string _name;

};

#endif /* ***************************************************** DIAMONDTRAP_H */