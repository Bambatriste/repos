#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm was built by default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:
Form ("RobotomyRequestForm", 72, 45, target)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm was built by default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
:
Form(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	Form::operator=(rhs);
	return *this;
}

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm  const &i)
{
	o << "Form = " << i.getName() << "; Min Req to sign  = " 
	<< i.getSignReq() << "; min req to exec = " << i.getExecReq() << ";is signed = " << i.getIsSigned();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int random;
	try
	{
		if (!getIsSigned())
			throw FormNotSignedException();
		else if (executor.getGrade() > getExecReq())
			throw GradeTooLowException();
		random = std::rand() % 2;
		if (random == 0)
			std::cout << getTarget() << " was successfully robotomized" << std::endl;
		else
			std::cout << "Failure of the robotomized procedure for " << getTarget() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << executor.getName() << " couldn't execute form : " << this->getName() << " : "<< e.what() << '\n';
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */