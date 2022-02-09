#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>

typedef enum e_type
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	WRONG_TYPE
}	t_type;

class Converter
{

	public:

		Converter();
		~Converter();
		void setType(char *input);
		void convertType();
		void displayTypes();

	private:
		Converter(Converter const &src);
		Converter &operator=( Converter const & rhs );
		int _type;
		char _chartypeValue;
		long int _longIntTypeValue;
		float _floatTypeValue;
		double _doubleTypeValue;
		void convert_double();
		void convert_longint();
		void convert_char();
		void convert_float();
		const char	*printDotZero( double number );
};

std::ostream &operator<<( std::ostream & o, Converter const & i );

#endif /* ******************************************************* CONVERTER_H */