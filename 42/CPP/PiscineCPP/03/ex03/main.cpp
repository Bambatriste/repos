#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int
	main(void)
{
	DiamondTrap	diamondtrap("Ditto");
	

	std::cout << "hitpoints : " << diamondtrap.getHitpoints() << std::endl;
	

	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	diamondtrap.attack("enemy");
	std::cout << "energy left : " << diamondtrap.getEnergy() << std::endl;
	diamondtrap.whoAmI();


	std::cout << std::endl << std::endl;

	DiamondTrap	diamondtrap2 = diamondtrap;
	diamondtrap2.guardGate();
	diamondtrap2.highFivesGuys();
	diamondtrap2.attack("enemy");
	std::cout << "energy left : " << diamondtrap2.getEnergy() << std::endl;
	diamondtrap2.whoAmI();


	std::cout << std::endl << std::endl;


	DiamondTrap	diamondtrap3(diamondtrap2);
	diamondtrap3.guardGate();
	diamondtrap3.highFivesGuys();
	diamondtrap3.attack("enemy");
	std::cout << "energy left : " << diamondtrap3.getEnergy() << std::endl;
	diamondtrap3.whoAmI();

	std::cout << std::endl << std::endl;
	
	return (0);
}

