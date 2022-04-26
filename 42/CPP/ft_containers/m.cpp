#include "pair.hpp"
#include <utility>
#include <string>
#include <iostream>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	//default constructor

	std::pair<int, std::string>p1;
	ft::pair<int , std::string>p2;

	std::cout << p1.first << std::endl;
	std::cout << p1.second << std::endl;

	std::cout << p2.first << std::endl;
	std::cout << p2.second << std::endl;

	// assignation constructor

	std::pair <int , std::string>p3(42,"abc");

	std::cout << p3.first << std::endl;
	std::cout << p3.second << std::endl;

	ft::pair <int, std::string>p4(42, "abc");

	std::cout << p4.first << std::endl;
	std::cout << p4.second << std::endl;

	// copy constructor

	std::pair <int , std::string>p6(p3);

	std::cout << p6.first << std::endl;
	std::cout << p6.second << std::endl;

	ft::pair <int , std::string>p7(p4);

	std::cout << p7.first << std::endl;
	std::cout << p7.second << std::endl;

	// operator=

	p6=p1;

	std::cout << p6.first << std::endl;
	std::cout << p6.second << std::endl;

	p7 = p2;

	std::cout << p7.first << std::endl;
	std::cout << p7.second << std::endl;

	//comparison operators :

	// ==

	std::cout << (p2 ==p7) << std::endl;
	//p7.first = 2;
	//p7.second = 33;
	std::cout << (p2 ==p7) << std::endl;

	// !=

	std::cout << (p2 !=p7) << std::endl;
	//p7.first = 2;
	//p7.second = 33;
	std::cout << (p2 !=p7) << std::endl;



	p2.first = 0;
	p7.first = 0;
	p2.second = "abc";
	p7.second = "abc";

	std::cout << "== :" << (p2 == p7) << std::endl;
	std::cout << "!= :" << (p2 != p7) << std::endl;
	std::cout << "< :" << (p2 <p7) << std::endl;
	std::cout << "<= :" << (p2 <=p7) << std::endl;
	std::cout << "> :" << (p2 >p7) << std::endl;
	std::cout << ">= :" << (p2 >=p7) << std::endl;


	std::pair<int, int> p9 = std::make_pair(12,13);

	std::cout << p9.first << std::endl;
	std::cout << p9.second << std::endl;


	ft::pair<int, int> p10 = ft::make_pair(12,13);

	std::cout << p10.first << std::endl;
	std::cout << p10.second << std::endl;



}