#ifndef SED42_HPP
# define SED42_HPP

#include <string.h>
#include <fstream>

class Sed42
{
private:
	std::string str_replace(std::string const &line, std::string const &search, std::string const &replace);
public:
	Sed42();
	~Sed42();
	void replace(std::string const &filename, std::string const &search, std::string const &replace);

};

#endif
