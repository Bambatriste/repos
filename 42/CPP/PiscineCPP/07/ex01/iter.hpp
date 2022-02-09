#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(const T *array, size_t size, void (*f) (const T &elem ))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template<typename T>
void iter(T *array, size_t size, void (*f)(T &elem))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	display(const T &a)
{
	std::cout << a << std::endl;
}

template <typename T>
void	increment(T &a)
{
	a++;
}


#endif