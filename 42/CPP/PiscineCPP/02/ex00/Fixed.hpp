#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=( Fixed const & rhs );
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int _value;
		static const int size = 8;
};

#endif /* *********************************************************** FIXED_H */
