#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm was built by default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:
Form ("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm was built by default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src)
:
Form(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	Form::operator=(rhs);
	return *this;
}

std::ostream &			operator<<( std::ostream &o, PresidentialPardonForm const &i)
{
	o << "Form = " << i.getName() << "; Min Req to sign  = " 
	<< i.getSignReq() << "; min req to exec = " << i.getExecReq() << ";is signed = " << i.getIsSigned();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!getIsSigned())
			throw FormNotSignedException();
		else if (executor.getGrade() > getExecReq())
			throw GradeTooLowException();
		std::cout << getTarget() << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute form : " << this->getName() << " : "<< e.what() << '\n';
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */