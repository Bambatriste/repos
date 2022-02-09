#include "Span.hpp"
#include <climits>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(void):
_size(0)
{
}

Span::Span(unsigned int N):
_size(N)
{
}

Span::Span(const Span &src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(void)
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const &rhs)
{
	if ( this != &rhs )
	{
		this->_size = rhs._size;
		this->_values = rhs._values;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void	Span::addNumber(int n)
	{
		if (_values.size() == _size)
			throw FullClassException();
		_values.push_back(n);
	}

	void	Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end)
	{

		if (this->_values.size() + std::distance(beg, end) > this->_size)
			throw FullClassException();
		while (beg != end)
		{
			_values.push_back(*beg);
			beg++;
		}
	}

	int		Span::shortestSpan(void) const
	{
		if (_values.size() <= 1)
			throw NoDistanceFoundException();
		int mindiff  = INT_MAX;
		std::vector<int>	cpy = _values;
		std::sort(cpy.begin(), cpy.end());
		for (size_t i = 1; i < _values.size(); i++)
		{
			if (mindiff > (cpy[i] - cpy[i - 1]))
				mindiff = (cpy[i] - cpy[i - 1]);
		}
		return mindiff;
	}

	int		Span::longestSpan(void)const
	{
		if ( _values.size() <= 1)
			throw NoDistanceFoundException();
		return (*std::max_element(_values.begin(), _values.end())
			- *std::min_element(_values.begin(), _values.end()));
	}

	void	Span::displayValues()
	{

		for (std::vector<int>::const_iterator i = _values.begin(); i != _values.end(); ++i)
			std::cout << *i << std::endl;
	}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
