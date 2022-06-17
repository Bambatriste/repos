#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <string>

class server
{
	public:
		server();
		server(server const &src);
		~server();
		server &operator=(server const &rhs);
	private:
};

std::ostream &operator<<(std::ostream &o, server const &instance);


#endif /* ************************************************************* SERVER_HPP */
