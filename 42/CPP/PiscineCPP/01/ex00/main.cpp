#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie zombie1;
	zombie1.set_name("Thomas");
	//Thomas created in this scope
	zombie1.announce();
	randomChump("Leo");
	//Leo created and destroyed instantly because out of scope
	Zombie *zombie2;
	zombie2 = newZombie("Nathalie");
	//created via pointer needs to be deleted
	delete zombie2;
	//Nathalie deleted

	return (0);
	//Thomas is now deleted at end of the scope by destructor
}

