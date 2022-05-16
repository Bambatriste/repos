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
		size_t		_capacity;

		public :

		//constructeurs
		vector()
		:
		_allocator(),
		_start(_allocator.allocate(0)),
		_end(_start),
		_capacity(0)
		{}
		explicit vector( const Allocator& alloc )
		:
		_allocator(alloc),
		_start(_allocator.allocate(0)),
		_end(_start),
		_capacity(0)
		{}
		// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		// :
		// _allocator(alloc)
		// {

		// }

		//functions


		/* capacity functions*/

		size_type size() const
		{return (_end - _start);}

		size_type max_size() const
		{return (_allocator.max_size());}

		size_type capacity() const
		{return (_capacity);}

		bool empty() const
		{return (_start == _end);}

		void reserve( size_type new_cap )
		{
			if (new_cap >= max_size())
				throw std::length_error("vector::reserve");
			if (new_cap > capacity())
			{
				pointer new_start;
				size_type old_size = size();

				new_start = _allocator.allocate(new_cap);
				for (size_type i =0; i < size(); i++)
				{
					_allocator.construct(new_start + i, _start[i]);
					_allocator.destroy(_start + i);
				}
				_allocator.deallocate(_start, capacity());
				_start = new_start;
				_end = _start + old_size;
				_capacity = new_cap;
			}
		}


		/* MODIFIERS */

		void push_back( const T& value )
		{
			T vcpy = value; // just in case reserve destroys it
			if ( size() + 1 > capacity())
			{
				if (size() == 0)
					reserve(1);
				else
					reserve(2 * capacity());
			}
			_allocator.construct(_end, vcpy);
			_end++;
		}

		void pop_back()
		{
			_allocator.destroy(_end - 1);
			_end--;
		}

		void clear()
		{
			for (size_type i; i < size(); i++)
			{
				_allocator.destroy(_start + i);
			}
			_end = _start;
		}

		iterator insert( iterator pos, const T& value )
		{
			size_t newsize = size() + 1;
			if ( size() + 1 > capacity())
			{
				if (size() == 0)
					reserve(1);
				else
					reserve(2 * capacity());
			}
			if (pos == _end)
			{
				_allocator.construct(_end, value);
				_end++;
			}
			else
			{
				size_type offset = _end - pos;
				std::cout << "offset :" << offset << std::endl;
				std::cout << "newsize :" << newsize << std::endl;

				while (offset)
				{
					_allocator.construct(_start + newsize, *(_start + newsize -1));
					newsize--;
					offset--;
				}
				_end++;
				*pos = value;
				return (pos);
			}
			return (pos);
		}



		// void insert( iterator pos, size_type count, const T& value );

		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last );

		/* ELEMENT ACCES*/

		reference back()
		{return (*(_end - 1));}

		reference operator[]( size_type pos )
		{return _start[pos];}

		const_reference operator[]( size_type pos ) const
		{return _start[pos];}

		reference at( size_type pos )
		{
			if (!(pos < size()))
				throw (std::out_of_range("ft::vector::at"));
			return _start[pos];
		}
		const_reference at( size_type pos ) const
		{
			if (!(pos < size()))
				throw (std::out_of_range("ft::vector::at"));
			return _start[pos];
		}

		reference front()
		{return (_start[0]);}
		const_reference front() const
		{return (_start[0]);}

			/* iterators */

		iterator begin()
		{return _start;}

		const_iterator begin() const
		{return _start;}

		iterator end()
		{return _end;}

		const_iterator end() const
		{return _end;}

		reverse_iterator rbegin()
		{return reverse_iterator(begin());}

		const_reverse_iterator rbegin() const
		{return reverse_iterator(begin());}

		reverse_iterator rend()
		{return reverse_iterator(end());}

		const_reverse_iterator rend() const
		{return reverse_iterator(end());}
	
	};




}

#endif /* ************************************************************* VECTOR_HPP */
