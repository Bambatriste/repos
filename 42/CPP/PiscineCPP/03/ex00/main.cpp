#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Roger");
	ClapTrap b("Martin");

	std::cout << "Martin has " << b.getHitpoints() << " hitpoints" << std::endl;
	a.setDamage(8);
	a.attack("Martin");
	b.takeDamage(a.getDamage());
	std::cout << "Martin has " << b.getHitpoints() << " hitpoints left" << std::endl;
	b.beRepaired(10);
	std::cout << "Martin has " << b.getHitpoints() << " hitpoints" << std::endl;
	a.attack("Martin");
	b.takeDamage(a.getDamage());
	a.attack("Martin");
	b.takeDamage(a.getDamage());
	std::cout << "Martin has " << b.getHitpoints() << " hitpoints left" << std::endl;
	std::cout << "Roger has " << a.getEnergy() << " energy points left" << std::endl;
	std::cout << "Martin has " << b.getEnergy() << " energy points left" << std::endl;

	ClapTrap z = b;
	std::cout << z.getName() << " has " << z.getHitpoints() << " hitpoints" << std::endl;

	ClapTrap y(a);
	std::cout << y.getName() << " has " << y.getEnergy() << " energy" << std::endl;

	return (0);
}
