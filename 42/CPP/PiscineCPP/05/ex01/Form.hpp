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
		Form(std::string const name, unsigned int min_sign_grade_, unsigned int min_exec_grade);
		Form( Form const &src);
		~Form();
		Form &operator=( Form const &rhs);
		const std::string getName(void) const;
		bool getIsSigned(void) const;
		unsigned int getSignReq() const;
		unsigned int getExecReq() const;
		void beSigned(Bureaucrat &bureaucrat);

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

	private:
		const std::string _name;
		bool _is_signed;
		unsigned const int _sign_grade_req;
		unsigned const int _exec_grade_req;

};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */