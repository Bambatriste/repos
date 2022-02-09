#include <string>
#include <fstream>
#include <iostream>

#include "Sed42.hpp"

int main(int ac , const char **av)
{
	if (ac != 4)
	{
		std::cout << "incorrect number of arguments" << std::endl;
		return (1);
	}
	Sed42 Sed;
	Sed.replace(av[1], av[2], av[3]);
}
