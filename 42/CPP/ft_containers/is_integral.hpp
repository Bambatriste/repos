#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <iostream>
# include <string>

class is_integral
{
	public:
		is_integral();
		is_integral(is_integral const &src);
		~is_integral();
		is_integral &operator=(is_integral const &rhs);
	private:
};

std::ostream &operator<<(std::ostream &o, is_integral const &instance);


#endif /* ************************************************************* IS_INTEGRAL_HPP */
