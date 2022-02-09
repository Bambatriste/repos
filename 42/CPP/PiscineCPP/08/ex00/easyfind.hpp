#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

class NotFoundException : public::std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("value was not found in container");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator ret;

	ret = std::find(container.begin(), container.end(), value);
	if (ret == container.end())
		throw NotFoundException();
	return (ret);
}

#endif