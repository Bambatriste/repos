#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

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
		Allocator		_allocator;
		pointer			_start;
		pointer			_end;
		size_type		_capacity;

		void	reallocate(size_t size_add)
		{
			size_t newsize = size() + size_add;
			if (newsize > capacity())
			{
				if (size() == 0)
					reserve(newsize);
				else
				{
					while (newsize > capacity())
					reserve(2 * capacity());
				}
			}
		}

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

		~vector()
		{
			for (size_type i = 0; i < size() ; i++) { _allocator.destroy(&_start[i]); }
			_allocator.deallocate(_start, _capacity);
		}

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
			//T vcpy = value; // just in case reserve destroys it
			reallocate(1);
			_allocator.construct(_end, value);
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
			if (pos == _end)
			{
				push_back(value);
				return (_end - 1);
			}
			difference_type n_move = _end - pos;
			reallocate(1);
			pointer previous = &_start[_end - begin() - 1];
			pointer current = previous + 1;
			for (difference_type i = 0; i < n_move; i++)
			{
				*current = *previous;
				--current;
				--previous;
			}
			_allocator.construct(current, value);
			_end++;
			return (current);
		}

		void insert( iterator pos, size_type count, const T& value )
		{
			if (count == 0)
				return ;
			difference_type n_moves = _end - pos;
			reallocate(count);
			difference_type capacity_diff = capacity() - size();
			//std::cout << std::endl;
			//std::cout << capacity() << std::endl;
			//std::cout << size() << std::endl;
			//std::cout << "capacity diff :" << capacity_diff << std::endl;
			//std::cout << "n moves:" << n_moves << std::endl;
			pointer previous = _end - 1;
			pointer current = previous + count;
			// decalage des anciens elements
			for (difference_type i = 0; i < n_moves; i++)
			{
				if (capacity_diff)
				{
					_allocator.construct(current, *previous);
					capacity_diff--;
				}
				else
					*current = *previous;
				--current;
				--previous;
			}
			//construction des nouveaux
			for (size_type i = 0; i < count; ++i)
			{
				if (capacity_diff)
				{
					_allocator.construct(current, value);
					capacity_diff--;
				}
				else
					*current = value;
				current--;
			}
			_end += count;
		}
		
		// template< class InputIt >
		// void insert( iterator pos,typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last )
		// {
		// 	size_t count = last - first;
		// 	size_t oldsize = size();
		// 	size_t newsize = oldsize + count;
		// 	if (newsize >= capacity())
		// 	{
		// 		if (size() == 0)
		// 			reserve(count);
		// 		else
		// 		while (newsize > capacity())
		// 			reserve(2 * capacity());
		// 	}
		// 	while (_start + newsize >= pos + count)
		// 	{
		// 		//std::cout << "elems to move right :" << *(_start +oldsize) << std::endl;
		// 		if (newsize > oldsize)
		// 			_allocator.construct(_start + newsize, *(_start + oldsize));
		// 		else
		// 			*(_start + newsize) = *(_start +oldsize);
		// 		oldsize--;
		// 		newsize--;
		// 	}
		// 	while (_start + newsize >= pos)
		// 	{
		// 		//std::cout << "elems to copy :" << *(last) << std::endl;
		// 		_allocator.construct(_start + newsize, *(last - 1));
		// 		last--;
		// 		newsize--;
		// 	}
		// 	_end += count;
		// }

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
