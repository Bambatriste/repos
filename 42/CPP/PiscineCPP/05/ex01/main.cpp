#include <string>
#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

int
	main(void)
{
	Bureaucrat	bureaucrat1("Thomas", 42);
	Bureaucrat	bureaucrat2("Antoine", 124);
	Form		form1("Alpha", 41, 1);
	Form		form2("Beta", 140, 1);
	Form		form3("Charlie", 151, 1);


	std::cout << bureaucrat1 << std::endl;
	std::cout << form1 << std::endl << form2 << std::endl;
	form1.beSigned(bureaucrat1);
	bureaucrat1.signForm(form1);
	std::cout << form1 << std::endl << form2 << std::endl;
	bureaucrat1.upgrade();
	std::cout << bureaucrat1 << std::endl;
	form1.beSigned(bureaucrat1);
	//bureaucrat1.signForm(form1);
	std::cout << form1 << std::endl << form2 << std::endl;
	return (0);
}
