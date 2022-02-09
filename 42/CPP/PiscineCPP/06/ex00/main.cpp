#include "Converter.hpp"

int main (int ac, char **av)
{
	Converter converter;

	if (ac != 2)
	{
		std::cout << "Invalid argument count" << std::endl;
		return (-1);
	}
	converter.setType(av[1]);
	converter.convertType();
	converter.displayTypes();

}