#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data()
:
_n(0),
_str("empty")
{

}

Data::Data(int n, std::string str)
:
_n(n),
_str(str)
{

}

Data::Data(Data &src )
{
	this->_n = src.getN();
	this->_str = src.getStr();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &				Data::operator=( Data & rhs )
{
	if ( this != &rhs )
	{
		this->_n = rhs.getN();
		this->_str = rhs.getStr();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Data &i )
{
	o << "value = " << i.getN() << std::endl << "str = " << i.getStr(); 
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/




/*
** --------------------------------- ACCESSOR ---------------------------------
*/
	int Data::getN()
	{
		return (this->_n);
	}

	std::string Data::getStr()
	{
		return (this->_str);

	}


/* ************************************************************************** */