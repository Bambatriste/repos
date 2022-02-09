#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{
	public:

		Span();
		Span(unsigned int N);
		Span( Span const &src);
		~Span();
		Span &operator=(Span const &rhs);
		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
		int		shortestSpan(void) const;
		int		longestSpan(void)const;
		void	displayValues();

	private:
		unsigned int _size;
		std::vector<int> _values;
	public :
	class FullClassException : public::std::exception
	{
    	public:
            virtual const char *what() const throw()
            {
                return ("Can't add more numbers");
            }
	};
	class NoDistanceFoundException : public::std::exception
	{
    	public:
            virtual const char *what() const throw()
            {
                return ("Can't find distance");
            }
	};
};
	
#endif /* ************************************************************ SPAN_H */