

#include "Player.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Player::Player()
:
Stack(0),
Hand(),
name("default")
{
}

Player::Player(int chips_value, std::string name)
:
Stack(chips_value),
Hand()
{
	this->name = name;

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Player::~Player()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
std::ostream &operator<<(std::ostream &o, Player const &instance)
{
	o << instance.name << instance.Stack << instance.Hand;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
