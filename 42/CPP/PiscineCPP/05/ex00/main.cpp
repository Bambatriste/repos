#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

int
	main(void)
{
	Bureaucrat	bureaucrat1("Martin", 2);
	Bureaucrat	bureaucrat2("Hubert", 150);
	Bureaucrat	bureaucrat3("Philippe", 151);
	Bureaucrat	bureaucrat4("Jean", 0);
	
	std::cout << bureaucrat1 << std::endl;
	bureaucrat1.upgrade();
	std::cout << bureaucrat1 << std::endl;
	//Error
	bureaucrat1.upgrade();
	std::cout << bureaucrat1 << std::endl;

	std::cout << bureaucrat2 << std::endl;
	//Error
	bureaucrat2.downgrade();
	std::cout << bureaucrat2 << std::endl;
	
	return (0);
}
