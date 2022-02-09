#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(void);
	~Zombie();
	void		set_name(std::string name);
	std::string get_name(void);
	void		announce(void);
};
#endif

