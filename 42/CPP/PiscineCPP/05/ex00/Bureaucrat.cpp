#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
:
_name("Stagiaire"),
_grade(150)
{
	std::cout << "A bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade)
:
_name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		_grade = grade;
		std::cout << "A bureaucrat has been created" << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << "Can't create Bureaucrat : " << e.what() <<std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << "Can't create Bureaucrat : " << e.what() <<std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	_grade = src._grade;
	std::cout << "A bureaucreat was created by copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat has ben destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs)
{
	if ( this != &rhs )
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << " Bureaucrat grade :" << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::upgrade(void)
{
	try
	{
		if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << "Can't upgrade bureaucrat : " << e.what() << std::endl;
	}
}

void	Bureaucrat::downgrade(void)
{
	try
	{
		if (_grade >= 150)
			throw GradeTooLowException();
		_grade++;
	}
	//catching here with std::exception instead of child
	catch(const std::exception& e)
	{
		std::cerr << "Can't downgrade bureaucrat : " << e.what() << std::endl;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	std::string const	Bureaucrat::getName(void) const
	{
		return this->_name;
	}

	unsigned int	Bureaucrat::getGrade(void) const
	{
		return this->_grade;
	}


/* ************************************************************************** */