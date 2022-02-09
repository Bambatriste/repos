#include <iostream>

#include "whatever.hpp"

int main()
{
	int a = 1;
	int b = 2;
	float c = 3.14;
	float d = 4.23;

	


	std::cout << "a : " << a << ", b : " << b << std::endl;
	std::cout <<  min(a, b) << " : is the lowest value" << std::endl;
	std::cout <<  max(a, b) << " : is the highest value" << std::endl;
	std::cout << "swap :" << std::endl;
	swap(a, b);
	std::cout << "a : " << a << ", b : " << b << std::endl;


	std::cout << std::endl << std::endl;

	std::cout << "c : " << c << ", d : " << d << std::endl;
	std::cout <<  min<float>(c, d) << " : is the lowest value" << std::endl;
	std::cout <<  max<float>(c, d) << " : is the highest value" << std::endl;
	std::cout << "swap :" << std::endl;
	swap(c, d);
	std::cout << "c : " << c << ", d : " << d << std::endl;




	return (0);
}