#include <iostream>
#include <cstdlib>


#include "ClassBase.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"

Base *generate()
{
	int rdm;

	
	rdm = std::rand() %3;
	if (rdm == 0)
		return (new A);
	else if (rdm == 1)
		return (new B);
	else
		return (new C);
}

/* dynamic cast is used at runtime and is used for downcasts*/

void identify(Base *p)
{
	A	*pa;
	B	*pb;
	C	*pc;

	pa = dynamic_cast<A *>(p);
	pb = dynamic_cast<B *>(p);
	pc = dynamic_cast<C *>(p);
	if (pa)
		std::cout << "A" << std::endl;
	else if (pb)
		std::cout << "B" << std::endl;
	else if (pc)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A	&ra = dynamic_cast<A &>(p);
		(void)ra;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B	&rb = dynamic_cast<B &>(p);
		(void)rb;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C	&rc = dynamic_cast<C &>(p);
		(void)rc;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}




int main()
{
	std::srand(time(NULL));
	Base *test;

	std::cout << "identify with ptr" << std::endl;
	test = generate();
	identify(test);
	std::cout << "identify with ref :" << std::endl;
	identify(*test);
	delete test;

	std::cout << "identify with ptr" << std::endl;
	test = generate();
	identify(test);
	std::cout << "identify with ref :" << std::endl;
	identify(*test);
	delete test;


	std::cout << "identify with ptr" << std::endl;
	test = generate();
	identify(test);
	std::cout << "identify with ref :" << std::endl;
	identify(*test);
	delete test;


	return (0);
}