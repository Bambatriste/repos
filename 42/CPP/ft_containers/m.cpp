#include "pair.hpp"
#include <utility>
#include <string>
#include <iostream>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::pair<int, std::string>p1;
	ft::pair<int , std::string>p2;

	std::cout << p1.first << std::endl;
	std::cout << p1.second << std::endl;

	std::cout << p2.first << std::endl;
	std::cout << p2.second << std::endl;

	std::pair <int , std::string>p3(42,"abc");

	std::cout << p3.first << std::endl;
	std::cout << p3.second << std::endl;


	ft::pair <int, std::string>p4(42, "abc");

	std::cout << p4.first << std::endl;
	std::cout << p4.second << std::endl;
}