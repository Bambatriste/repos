# include <string>
# include <iostream>

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

int
	main(void)
{
	// Bureaucrat				bureaucrat1("Antoine", 1);
	// Bureaucrat				bureaucrat2("Henri", 150);

	// PresidentialPardonForm	presform("some_dude");

	// std::cout << presform<< std::endl;
	// std::cout << bureaucrat1 << std::endl;
	// std::cout << bureaucrat2 << std::endl;

	// presform.beSigned(bureaucrat2);
	// bureaucrat2.signForm(presform);
	// bureaucrat1.executeForm(presform);
	// presform.execute(bureaucrat1);
	// bureaucrat1.signForm(presform);
	// presform.execute(bureaucrat2);
	// bureaucrat2.executeForm(presform);
	// presform.execute(bureaucrat1);
	// bureaucrat1.executeForm(presform);


	// Bureaucrat	bureaucrat1("Antoine", 1);
	// Bureaucrat	bureaucrat2("Henri", 150);
	// RobotomyRequestForm	roboform("some_dude");
	// std::cout << roboform << std::endl;
	// std::cout << bureaucrat1 << std::endl;
	// std::cout << bureaucrat2 << std::endl;
	// roboform.beSigned(bureaucrat2);
	// bureaucrat2.signForm(roboform);
	// bureaucrat1.executeForm(roboform);
	// roboform.execute(bureaucrat1);
	// bureaucrat1.signForm(roboform);
	// roboform.execute(bureaucrat2);
	// bureaucrat2.executeForm(roboform);
	// roboform.execute(bureaucrat1);
	// bureaucrat1.executeForm(roboform);




	Bureaucrat	bureaucrat1("Antoine", 1);
	Bureaucrat	bureaucrat2("Henri", 150);
	ShrubberyCreationForm treeForm("some_dude");
	std::cout << treeForm << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	treeForm.beSigned(bureaucrat2);
	bureaucrat2.signForm(treeForm);
	bureaucrat1.executeForm(treeForm);
	treeForm.execute(bureaucrat1);
	bureaucrat1.signForm(treeForm);
	treeForm.execute(bureaucrat2);
	bureaucrat2.executeForm(treeForm);
	treeForm.execute(bureaucrat1);
	bureaucrat1.executeForm(treeForm);


	return (0);
}
