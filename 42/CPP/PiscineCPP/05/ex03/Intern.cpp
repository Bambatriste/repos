#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "An intern was built" << std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "An intern was destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<(std::ostream &o, Intern const &i)
{
	(void)i;
	o << "a random intern";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static Form	*createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static Form	*createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string const &name, std::string const &target)
{
	Form *ret = NULL;
	typedef Form* (*function)(std::string const &target);
	typedef struct { std::string name; function f; } form_types;

	form_types	forms[] = {
		{"shrubbery creation", &createShrubberyCreationForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"presidential pardon", &createPresidentialPardonForm}
	};
	for (int i = 0; i < 3 ; i++)
	{
		if (forms[i].name == name)
		{
			ret = forms[i].f(target);
			std::cout << "Intern creates " << ret->getName() <<  std::endl;
			return (ret);
		}
	}
	std::cout << "Intern could not create " << name << std::endl;
	return (ret);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */