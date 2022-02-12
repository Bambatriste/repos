#! /bin/bash

#simple class Builder for improve quality of life


echo "enter class name :"
read st1

hpp_name=$st1.hpp
cpp_name=$st1.cpp
CAPS_NAME=${st1^^}
HPP="_HPP"
CAPS_HPP=$CAPS_NAME$HPP

touch $PWD $cpp_name
touch $PWD $hpp_name

echo "#ifndef $CAPS_HPP
# define $CAPS_HPP

# include <iostream>
# include <string>

class $st1
{
	public:
		$st1();
		$st1($st1 const &src);
		~$st1();
		$st1 &operator=($st1 const &rhs);
	private:
};

std::ostream &operator<<(std::ostream &o, $st1 const &instance);


#endif /* ************************************************************* $CAPS_HPP */" > $hpp_name


echo "

#include "$hpp_name"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

$st1::$st1()
{
}

$st1::$st1(const $st1&src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

$st1::~$st1()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

$st1	&$st1::operator=($st1 const &rhs)
{
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */" > $cpp_name




