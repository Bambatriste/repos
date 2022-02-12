#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <string>

class Player
{
	public:
		Player();
		Player(Player const &src);
		~Player();
		Player &operator=(Player const &rhs);
	private:
};


#endif /* ************************************************************* PLAYER_HPP */
