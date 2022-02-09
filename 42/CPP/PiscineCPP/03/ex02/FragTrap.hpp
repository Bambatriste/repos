#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		FragTrap();
		~FragTrap();
		FragTrap &operator=( FragTrap const & rhs );
		void	attack(std::string const & target);
		void	highFivesGuys(void);
	private:
		std::string _name;

};


#endif /* ******************************************************** FRAGTRAP_H */