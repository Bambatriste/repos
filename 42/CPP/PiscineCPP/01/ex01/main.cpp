#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie *zombie_horde;
	int n = 5;

	zombie_horde = zombieHorde(n, "Jack Sparrow");
	for (int i = 0; i < n; i++)
	{
		zombie_horde[i].announce();
	}
	delete [] zombie_horde;
}
