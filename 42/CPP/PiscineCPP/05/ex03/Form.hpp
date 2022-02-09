#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string const name, unsigned int min_sign_grade_, unsigned int min_exec_grade, const std::string &target);
		Form( Form const &src);
		virtual ~Form();
		Form &operator=( Form const &rhs);
		const std::string getName(void) const;
		bool getIsSigned(void) const;
		unsigned int getSignReq() const;
		unsigned int getExecReq() const;
		void beSigned(Bureaucrat &bureaucrat);
		std::string const getTarget(void) const;
		virtual void execute(Bureaucrat const &executor) const = 0;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade Too high");
				}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade Too low");
				}
		};
		class FormNotSignedException : public std::exception 
		{
			
			public:
			virtual const char	*what() const throw()
			{
				return ("Form not signed");
			}
		};
		class CantOpenFileException : public std::exception 
		{
			public:
			virtual const char	*what() const throw()
			{
				return ("can't open file");
			}
		};

	private:
		const std::string _name;
		bool _is_signed;
		unsigned const int _sign_grade_req;
		unsigned const int _exec_grade_req;
		std::string const	_target;

};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */