#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <string>

#include "../bot.hpp"

class Player
{
	public:
		Player();
		Player(int chips_value, std::string name);
		~Player();
		Stack Stack;
		Hand Hand;
		//int timer;
		std::string name;
};

std::ostream &operator<<(std::ostream &o, Player const &instance);


#endif /* ************************************************************* PLAYER_HPP */
