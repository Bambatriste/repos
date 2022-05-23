#ifndef ALGORITHMS_HPP
# define ALGORITHMS_HPP

# include <iostream>
# include <string>

namespace ft
{
	template<class T>
	void swap(T& a , T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}
}


#endif /* ************************************************************* ALGORITHMS_HPP */
