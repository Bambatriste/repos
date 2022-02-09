#include "Sed42.hpp"

#include <iostream>
#include <string>

Sed42::Sed42()
{
}

Sed42::~Sed42()
{
}

std::string Sed42::str_replace(std::string const &line, std::string const &search, std::string const &replace)
{
	std::string newline;
	size_t j = 0;

	for (size_t i = 0; i < line.length(); i++)
	{
		j = 0;
		while (line[j + i] == search[j] && j < search.length())
			j++;
		if (j == search.length())
		{
			newline += replace;
			i += search.length() - 1;
		}
		else
			newline += line[i];
	}
	return (newline);
}

void	Sed42::replace(std::string const &filename, std::string const &search, std::string const &replace)
{
	std::ifstream file;
	std::ofstream file_out;
	std::string line;
	std::string newfile = filename + ".replace";

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Couldn't open filename" << std::endl;
		return ;
	}
	file_out.open(newfile.c_str(), std::ios::trunc);
	while (std::getline(file, line))
	{
		file_out << this->str_replace(line, search, replace);
		file_out << '\n';
	}
	file.close();
	file_out.close();
}



