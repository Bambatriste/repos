#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>

class Stack
{
	public:
		Stack();
		Stack(Stack const &src);
		~Stack();
		Stack &operator=(Stack const &rhs);
	private:
};


#endif /* ************************************************************* STACK_HPP */
