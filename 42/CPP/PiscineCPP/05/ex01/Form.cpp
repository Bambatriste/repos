#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


Form::Form()
:
_name("DEFAULT_FORM"),
_is_signed(false),
_sign_grade_req(0),
_exec_grade_req(0)
{
	std::cout << this->getName() << " Form was built" << std::endl;
}

Form::Form(std::string const name, unsigned int min_sign, unsigned int min_exec)
:
_name(name),
_is_signed(false),
_sign_grade_req(min_sign),
_exec_grade_req(min_exec)
{
	try
	{
		if (_sign_grade_req < 1 || _exec_grade_req < 1)
			throw GradeTooHighException();
		else if (_sign_grade_req >150 || _exec_grade_req > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "couldn't create form : " << this->getName() << " : "<< e.what() << '\n';
	}
}

Form::Form(const Form &src)
:
_name(src.getName()),
_is_signed(src.getIsSigned()),
_sign_grade_req(src.getSignReq()),
_exec_grade_req(src.getExecReq())
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "form : " << this->getName() << " was destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	this->_is_signed = rhs.getIsSigned();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form = " << i.getName() << "; Min Req to sign  = " 
	<< i.getSignReq() << "; min req to exec = " << i.getExecReq() << ";is signed = " << i.getIsSigned();

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->getSignReq())
			throw GradeTooLowException();
		_is_signed = true;
		std::cout << "form : " << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "couldn't sign form : " << this->getName() << " " << bureaucrat.getName() << " : " << e.what() << '\n';
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	const std::string  Form::getName(void) const
	{
		return this->_name;

	}
	bool Form::getIsSigned(void) const
	{
		return this->_is_signed;

	}
	unsigned int Form::getSignReq() const
	{
		return this->_sign_grade_req;

	}
	unsigned int Form::getExecReq() const
	{
		return this->_exec_grade_req;
	}


/* ************************************************************************** */