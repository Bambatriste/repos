#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Node.hpp"
# include "iterators_traits.hpp"
#include "map.hpp"
#include "pair.hpp"

namespace ft

{
	template <class Category,
				class T,
				class Distance = std::ptrdiff_t,
				class Pointer = T*,
				class Reference = T&>
	class iterator {
	public:

		typedef	Category	iterator_category;
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	T*			pointer;
		typedef	T&			reference;

	};

	template < class T>
	class map_iterator
	{
		public:

		typedef iterator<std::bidirectional_iterator_tag , T> 				iterator;
		typedef	ft::iterator_traits<iterator>								iterator_traits;
		typedef	typename 	iterator_traits::difference_type				difference_type;
		typedef typename 	iterator_traits::value_type						value_type;
		typedef typename	iterator_traits::pointer						pointer;
		typedef typename	iterator_traits::reference						reference;
		typedef typename	iterator_traits::iterator_category				iterator_category;
		typedef typename 	value_type::first_type							key_type;
		typedef const 		key_type										const_key_type;
		typedef typename	value_type::second_type							mapped_type;
		typedef				Node<const_key_type, mapped_type>						node;
		typedef				node*											node_pointer;

		node_pointer _p;

		map_iterator()
		{
			_p = NULL;
		}

		map_iterator(node_pointer p)
		:
		_p(p)
		{}

		map_iterator(map_iterator const &src)
		:
		_p (src._p)
		{}

		map_iterator& operator=(const map_iterator& src)
		{
			_p = src._p;
			return *this;
		}

		~map_iterator()
		{}

		//operator map_iterator<const value_type> () const { return _p; }

		map_iterator& operator++()
		{
			if (_p->right)
			{
				_p = _p->right;
				while(_p->left)
				{
					_p = _p->left;
				}
			}
			else
			{
				node_pointer tmp = _p;
				while(tmp)
				{
					if  (!tmp->parent)
					{
						_p = _p->right;
						return *this;
					}
					else if (tmp == tmp->parent->left)
					{
						_p = tmp->parent;
						return *this;
					}
					tmp = tmp->parent;
				}
			}
			return *this;
		}

		map_iterator operator++(int)
		{
			map_iterator ret = *this;
			++(*this);
			return ret;
		}

		pointer operator->() const{ return &(*_p->content); }
	};
}



#endif /* ************************************************************* MAP_ITERATOR_HPP */
