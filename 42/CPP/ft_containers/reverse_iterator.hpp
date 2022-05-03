#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
#include "iterators_traits.hpp"

namespace ft 
{
	template< class Iter >
	class reverse_iterator
	{
		public :
			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type 			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer 			pointer;
			typedef typename ft::iterator_traits<Iter>::reference 			reference;

			constructor();
			operator=;
			base();
			operator*;
			operator->;
			operator[];
			operator++;
			operator++(int);
			operator+=;
			operator+;
			operator--;
			operator--(int);
			operator-=;
			operator-;

			//non members : static keyword?

			operator==;
			operator!=;
			operator<;
			operator<=;
			operator>;
			operator>=;
			operator+;
			operator-;
			
		protected:
			Iter iter; // underlying iterator?

	};
}


#endif /* ************************************************************* REVERSE_ITERATOR_HPP */
