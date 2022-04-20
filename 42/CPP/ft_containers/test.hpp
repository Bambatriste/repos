#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>

class test
{
	public:
		test();
		test(test const &src);
		~test();
		test &operator=(test const &rhs);
	private:
};

std::ostream &operator<<(std::ostream &o, test const &instance);


#endif /* ************************************************************* TEST_HPP */
