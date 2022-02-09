#include "iter.hpp"

void float_increment(float &value)
{
	value++;
}

void float_display(float &value)
{
	std::cout << value << std::endl;
}

int main()
{
	float tab [3] = { 1.1, 2.4 , 5.55};
	std::string	s[] = {"Hello", "pouet"};

	iter(tab, 3, float_display);
	iter(tab, 3, float_increment);
	iter(tab, 3, float_display);

	iter(s, 2, display);

	return (0);
}