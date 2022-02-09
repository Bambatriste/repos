#include <iostream>
#include "Karen.hpp"

int
	get_level_value(std::string level)
{
	std::string	level_names[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
		if (!level.compare(level_names[i]))
			return (i);
	return (-1);
}

int
	main(int argc, char **argv)
{
	Karen		karen;
	std::string	level;
	int			level_value;

	if (argc != 2)
		return (1);
	level = argv[1];
	level_value = get_level_value(level);
	switch (level_value)
	{
		case 0:
			karen.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			karen.complain("INFO");
			std::cout << std::endl;
		case 2:
			karen.complain("WARNING");
			std::cout << std::endl;
		case 3:
			karen.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
