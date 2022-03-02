#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <string>

#include "../bot.hpp"

class Game
{
	public:
		Game();
		~Game();
		std::vector<Player> Players;
		Deck Deck;
};

std::ostream &operator<<(std::ostream &o, Game const &instance);


#endif /* ************************************************************* GAME_HPP */
