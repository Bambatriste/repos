#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed(void);
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed	&operator=( Fixed const & rhs );
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
	
		int					_value;
		static const int 	_fractional = 8;
};

std::ostream	&operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */
