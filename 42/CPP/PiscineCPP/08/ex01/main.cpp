#include <string>
#include <iostream>
#include <vector>

#include "Span.hpp"


int main()
{
	Span sp = Span(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
    {
		sp.addNumber(10);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::vector<int>v_test(100, 42);
	Span sp2(100);

	try
	{
		sp2.addRange(v_test.begin(), v_test.end() - 95);
	}
	catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	// test for range 
	sp2.displayValues();


	
	
	return 0;
}
