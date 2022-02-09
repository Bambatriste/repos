#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string const name, unsigned int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);
		std::string const	getName(void) const;
		unsigned int		getGrade(void) const;
		void				upgrade(void);
		void				downgrade(void);
		void				signForm(Form &form);
		void				executeForm(Form const &form);
		class				GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade Too high");
				}
		};

		class				GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade Too low");
				}
		};

	private:
		std::string const _name;
		unsigned int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);


#endif /* ****************************************************** BUREAUCRAT_H */