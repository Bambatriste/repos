#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{

	public:

		Data();
		Data( Data & src );
		Data(int n, std::string str);
		~Data();
		Data &operator=( Data & rhs );
		int getN();
		std::string getStr();

	private:
		int _n;
		std::string _str;

};

std::ostream &operator<<( std::ostream & o, Data & i );

#endif /* ************************************************************ DATA_H */