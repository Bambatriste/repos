#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <string>

class Game
{
	public:
		Game();
		Game(Game const &src);
		~Game();
		Game &operator=(Game const &rhs);
	private:
};


#endif /* ************************************************************* GAME_HPP */
