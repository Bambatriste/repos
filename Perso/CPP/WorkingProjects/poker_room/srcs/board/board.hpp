#ifndef BOARD_HPP
# define BOARD_HPP

# include <iostream>
# include <string>

#include "../deck/Deck.hpp"

class board
{
	public:
		board();
		~board();
		void draw(Deck &deck);
		std::vector<Card> getCards()const;
	private:
		std::vector<Card> cards;
};

std::ostream &operator<<(std::ostream &o, board const &instance);


#endif /* ************************************************************* BOARD_HPP */
