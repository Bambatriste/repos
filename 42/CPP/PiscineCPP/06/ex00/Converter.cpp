#include "Converter.hpp"



/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter()
:
_type (-1),
_chartypeValue(0),
_longIntTypeValue(0),
_floatTypeValue(0),
_doubleTypeValue(0)
{

}

Converter::Converter( const Converter &src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Converter &	Converter::operator=( Converter const &rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void Converter::convert_char()
{
	this->_doubleTypeValue = static_cast<double>(this->_chartypeValue);
	this->_floatTypeValue = static_cast<float>(this->_chartypeValue);
	this->_longIntTypeValue= static_cast<long int>(this->_chartypeValue);
}

void Converter::convert_double()
{
	this->_chartypeValue = static_cast<char>(this->_doubleTypeValue);
	this->_floatTypeValue = static_cast<float>(this->_doubleTypeValue);
	this->_longIntTypeValue = static_cast<long int>(this->_doubleTypeValue);
}

void Converter::convert_longint()
{
	this->_chartypeValue = static_cast<char>(this->_longIntTypeValue);
	this->_doubleTypeValue = static_cast<double>(this->_longIntTypeValue);
	this->_floatTypeValue = static_cast<float>(this->_longIntTypeValue);
}

void Converter::convert_float()
{
	this->_chartypeValue = static_cast<char>(this->_floatTypeValue);
	this->_doubleTypeValue = static_cast<double>(this->_floatTypeValue);
	this->_longIntTypeValue = static_cast<long int>(this->_floatTypeValue);
}

void Converter::convertType()
{
	if (this->_type == DOUBLE_TYPE)
		this->convert_double();
	else if (this->_type == INT_TYPE)
		this->convert_longint();
	else if (this->_type == CHAR_TYPE)
		this->convert_char();
	else if (this->_type == FLOAT_TYPE)
		this->convert_float();
}

const char	*Converter::printDotZero(double number)
{
	if (number - static_cast<int>(number) == 0.0)
		return (".0");
	return ("");
}

bool canShowInt(long int number)
{
	return ((number <= std::numeric_limits<long int>::max()
		&& number >= -std::numeric_limits<long int>::max())
		|| std::isnan(number));

}

bool canShowFloat(float number)
{
	return ((number <= std::numeric_limits<float>::max()
			&& number >= -std::numeric_limits<float>::max())
			|| std::isnan(number));
}

bool canShowDouble(double number)
{
	return ((number <= std::numeric_limits<double>::max()
	&& number >= -std::numeric_limits<double>::max())
	|| std::isnan(number));

}

void Converter::displayTypes()
{
	if (this->_type == WRONG_TYPE)
		return;
	if (std::isnan(this->_doubleTypeValue))
		std::cout << "char : Impossible" << std::endl;
	else
	{
		if (this->_chartypeValue < 32 || this->_chartypeValue > 127)
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : " << this->_chartypeValue << std::endl;
	}
	if (canShowInt(this->_longIntTypeValue))
		std::cout << "int : " << this->_longIntTypeValue << std::endl;
	else
		std::cout << "int : impossible" << std::endl;

	if (canShowFloat(this->_floatTypeValue))
	{
		std::cout << "float : " << this->_floatTypeValue;
		std::cout << printDotZero(this->_floatTypeValue);
		std::cout << "f";
		std::cout << std::endl;
	}
	else
		std::cout << "float : impossible" << std::endl;

	if(canShowDouble(this->_doubleTypeValue))
	{
		std::cout << "double : " << this->_doubleTypeValue;
		std::cout << printDotZero(this->_doubleTypeValue );
		std::cout << std::endl;
	}
	else
		std::cout << "double : impossible" << std::endl;

}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Converter::setType(char *input)
{
	char *end = NULL;

	strtol(input, &end, 10);
	if (*end == '\0')
	{
		this->_type = INT_TYPE;
		this->_longIntTypeValue = strtol(input, &end, 10);
		return ;
	}
	this->_doubleTypeValue = strtod(input, &end);
	if (*end == '\0')
	{
		this->_type = DOUBLE_TYPE;
		this->_doubleTypeValue = strtod(input, &end);
		return;
	}
	strtof(input, &end);
	if (*end == 'f')
	{
		this->_type = FLOAT_TYPE;
		this->_floatTypeValue = strtof(input, &end);
		return ;
	}
	if ( input[0] && !input[1] && !(input[0] >= '0' && input[0] <= '9'))
	{
		this->_type = CHAR_TYPE;
		this->_chartypeValue = input[0];
		return;
	}
	this->_type = WRONG_TYPE;
	std::cout << "Wrong input" << std::endl;
}


/* ************************************************************************** */