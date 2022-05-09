#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "reverse_iterator.hpp"

namespace ft 
{
	template <class T, class Allocator = std::allocator<T> >
	class vector 
	{


		public:
		// types:
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference 			const_reference;
		typedef T* 												iterator;
		typedef const T* 										const_iterator;
		typedef std::size_t 									size_type; 
		typedef std::ptrdiff_t									difference_type;
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename										Allocator::pointer pointer;
		typedef typename										Allocator::const_pointer const_pointer;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;


		private:
		Allocator	_allocator;
		pointer		_start;
		pointer		_end;


		public :

		//constructeurs
		vector()
		:
		_allocator(),
		_start(_allocator.allocate(0)),
		_end(_start)
		//_end_capacity(_end)
		{}
		explicit vector( const Allocator& alloc )
		:
		_allocator(alloc),
		_start(_allocator.allocate(0)),
		_end(_start)
		{}
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		:
		_allocator(alloc)
		{
			for (size_type i = 0, i < count, i++;)
			{

			}
		}

		//functions
		void assign( size_type count, const T& value )
		{

		}


	};


}

#endif /* ************************************************************* VECTOR_HPP */
