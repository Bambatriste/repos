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
		pointer		_capacity;

		public :

		//constructeurs
		vector()
		:
		_allocator(),
		_start(_allocator.allocate(0)),
		_end(_start),
		_capacity(_end)
		{}
		explicit vector( const Allocator& alloc )
		:
		_allocator(alloc),
		_start(_allocator.allocate(0)),
		_end(_start),
		_capacity(_end)
		{}
		// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		// :
		// _allocator(alloc)
		// {

		// }

		//functions


		/* capacity functions*/

		size_type size() const
		{
			return (_end - _start);
		}
		size_type max_size() const
		{
			return (_allocator.max_size());
		}
		size_type capacity() const
		{
			return (_capacity);
		}

		void reserve( size_type new_cap )
		{
			if (new_cap >= max_size())
				throw std::length_error("vector::reserve");
			if (new_cap > capacity())
			{
				pointer new_start;
				size_type old_size = size();

				new_start = _allocator.allocate(new_cap);
				for (int i =0; i++; i < size())
				{
					_allocator.construct(new_start + i, _start[i]);
					_allocator.destroy(_start + i));
				}
				_allocator.deallocate(_start, capacity());
				_start = new_start;
				_end = _start + old_size;
				_capacity = new_cap;
			}
		}

		//modifiers

		// iterator insert( iterator pos, const T& value )
		// {

		// }

		void push_back( const T& value )
		{

		}

		void pop_back();

	};


}

#endif /* ************************************************************* VECTOR_HPP */
