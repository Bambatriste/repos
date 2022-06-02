#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Node.hpp"
# include "iterators_traits.hpp"

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
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> 
	{
		public:

		typedef iterator<std::bidirectional_iterator_tag , T> iterator;
		typedef	std::bidirectional_iterator_tag			iterator_category;
		typedef	std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef typename value_type::first_type			key_type;
		typedef typename value_type::second_type		mapped_type;
		typedef iterator_traits<map_iterator>			iterator_traits;
		typedef Node<key_type, mapped_type>				node;
		typedef node*									node_pointer;

		node_pointer _p;

		map_iterator(node_pointer p = 0)
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

		operator map_iterator<const value_type> () const { return _p; }

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
	};
}



#endif /* ************************************************************* MAP_ITERATOR_HPP */
