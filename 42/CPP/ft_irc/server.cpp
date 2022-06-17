

#include "server.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

server::server()
{
}

server::server(const server&src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

server::~server()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

server	&server::operator=(server const &rhs)
{
	return *this;
}

std::ostream &operator<<(std::ostream &o, server const &instance)
{
	//o << instance.value;
	//return (o);
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
