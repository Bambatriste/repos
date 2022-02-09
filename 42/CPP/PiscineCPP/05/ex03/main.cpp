#include <string>
#include <iostream>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int
	main(void)
{
	Intern	someRandomIntern;
	Form	*rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf == NULL)
		return (0);

	Bureaucrat	bureaucrat1("Antoine", 1);
	Bureaucrat	bureaucrat2("Henri", 150);
	std::cout << *rrf << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	rrf->beSigned(bureaucrat2);
	bureaucrat2.signForm(*rrf);
	bureaucrat1.executeForm(*rrf);
	rrf->execute(bureaucrat1);
	bureaucrat1.signForm(*rrf);
	rrf->execute(bureaucrat2);
	bureaucrat2.executeForm(*rrf);
	rrf->execute(bureaucrat1);
	bureaucrat1.executeForm(*rrf);

	delete rrf;

	return (0);
}
