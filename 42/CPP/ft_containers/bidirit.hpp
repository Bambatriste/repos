#ifndef BIDIRIT_HPP
# define BIDIRIT_HPP

# include <iostream>
# include <string>

namespace ft
{
	class bidirit
	{
		public:
			bidirit();
			bidirit(bidirit const &src);
			~bidirit();
			bidirit &operator=(bidirit const &rhs);
		private:
	};
}

//std::ostream &operator<<(std::ostream &o, bidirit const &instance);


#endif /* ************************************************************* BIDIRIT_HPP */
