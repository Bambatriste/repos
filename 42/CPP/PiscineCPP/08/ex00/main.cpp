#include "easyfind.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


int main()
{
	std::vector<int> values;
	std::vector<int>::iterator v_iterator;

	for (int i = 0; i < 6; i++)
		values.push_back(i);

	try
	{
		v_iterator = easyfind(values, 5);
		std::cout << "was was found for test 1!" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	values.pop_back();
	//remove elem 5 of value 5
	try
	{
		v_iterator = easyfind(values, 5);
		std::cout << "was was found for test 2!" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}