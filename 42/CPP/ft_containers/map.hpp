#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "iterators_traits.hpp"
# include "algorithms.hpp"
# include "Node.hpp"
# include "map_iterator.hpp"
#include <vector>
#include <math.h>

namespace ft 
{
    template<class Key,
             class T,
            class Compare = std::less<Key>,
            class Allocator = std::allocator<ft::pair<const Key, T> > 
            >
    class map
    {
        public:
		// types:
        typedef const Key                                                   key_type;
        typedef T                         			                        mapped_type;
        typedef ft::pair<const Key, T>                                      value_type;                               
        typedef std::size_t	        							            size_type; 
        typedef std::ptrdiff_t									            difference_type;
        typedef Compare										                key_compare;
        typedef Allocator										            allocator_type;
        typedef value_type&                                                 reference;
        typedef const value_type&                                           const_reference;
        typedef typename Allocator::pointer						            pointer;
        typedef typename Allocator::const_pointer				            const_pointer;
        typedef ft::map_iterator<value_type>                                iterator;
        typedef const iterator	                                            const_iterator;
        typedef ft::reverse_iterator<iterator>					            reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>	                    const_reverse_iterator;
        typedef Node<key_type, mapped_type>                                 node;
        typedef node*                                                       node_pointer;
        typedef typename    allocator_type::template rebind<node>::other	alnode;

        class value_compare
        {
            friend class map;
            protected:
                Compare comp;
                value_compare(Compare c):comp(c){}
            public:
                typedef bool                                                result_type;
                typedef value_type                                          first_argument_type;
                typedef value_type                                          second_argument_type;
                bool operator()(const first_argument_type& lhs, const second_argument_type &rhs)
                {
                    return comp(lhs.first, rhs.first);
                }
        };

        private:

        allocator_type  _allocator;
        alnode          _node_allocator;
        node_pointer    _root;
        node_pointer    _end;
        size_type       _size;
        key_compare     _comp;

        public:

        //constructeurs :

        explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		: 
        _allocator(alloc),
        _node_allocator(alloc),
        _root(0),
        _end(0),
        _size(0),
        _comp(comp)
		{
			create_end_node();
		}

        ~map()
        {}

        // explicit map (key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		// : 
        // _allocator(alloc),
        // _node_allocator(alloc),
        // _root(0),
        // _end(0),
        // _comp(comp)
		// {
		// 	create_end_node();
		// }

        // template< class InputIt >
        // map( InputIt first, InputIt last,
        // const Compare& comp = Compare(),
        // const Allocator& alloc = Allocator() );

        // CAPACITY

        bool empty() const { return _size == 0; }

        //explicit map( const Compare& comp, const Allocator& alloc = Allocator() );


        //MODIFIERS

        // ft::pair<iterator, bool> insert( const value_type& value )
        // {
        //     insert_node(value);
        // }

        //ACCESSORS

        iterator begin()
        {
            return (iterator(get_leftmost_node()));
        }

        iterator end()
        {
            return(iterator(_end));
        }

        iterator rbegin()
        {
            return reverse_iterator(end());
        }

        iterator rend()
        {
            return reverse_iterator(begin());
        }

        pair<iterator, bool> insert(const value_type& content)
        {
            if (!_root)
            {
                _root = create_node(content, 0);
                _root->color = BLACK;
                update_end_node();
                return ft::make_pair(iterator(_root), true);
            }
            node_pointer tmp = _root;
            while (tmp)
            {
                if (_comp(content.first, tmp->content->first))
                {
                    if (!tmp->left)
                    {
                        tmp->left = create_node(content, tmp);
                        update_end_node();
                        return ft::make_pair(iterator(tmp->left), true);
                    }
                    tmp = tmp->left;
                }
                else
                {
                    if (!tmp->right || is_sentinel(tmp->right))
                    {
                        tmp->right = create_node(content, tmp);
                        update_end_node();
                        return ft::make_pair(iterator(tmp->right), true);
                    }
                    tmp = tmp->right;
                }
            }
            return ft::make_pair(iterator(tmp), false);
        }

        private:

        node_pointer create_node(const value_type &content, node_pointer parent)
        {
            node_pointer new_node = _node_allocator.allocate(1);
            new_node->content = _allocator.allocate(1);
            _allocator.construct(new_node->content, content);
            new_node->left = 0;
            new_node->right = 0;
            new_node->parent = parent;
            new_node->color = RED;
            ++_size;
            return new_node;
        }

        void create_end_node()
        {
            _end = _node_allocator.allocate(1);
            _end->content = 0;
            _end->left = 0;
            _end->right = 0;
            _end->parent = 0;
        }

        void    update_end_node()
        {
            if (this->empty())
                return ;
            else
            {
                node_pointer tmp = get_rightmost_node();
                tmp->right = _end;
                _end->parent = tmp;
            }
        }

        node_pointer get_rightmost_node()
        {
            if (this->empty())
				return 0;
            node_pointer tmp = _root;
            while (tmp->right && (!is_sentinel(tmp->right)))
                tmp = tmp->right;

            return tmp;
        }

        node_pointer get_leftmost_node()
        {
            if (this->empty())
				return 0;
            node_pointer tmp = _root;
            while (tmp->left && (!is_sentinel(tmp->left)))
                tmp = tmp->left;
            return tmp;
        }



        //todo :

        // iterators
        // accessor
        // add red black rules


        /***********************************************DISPLAY FUNCTIONS ***************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/
        /********************************************************************************************************************/


        void    display_self(node_pointer node = 0)
        {
            if (!node)
            {
                node = _root;
                if (!node)
                    return;
            }
            if (node->left && !is_sentinel(node->left))
            {
                display_self(node->left);
            }
            std::cout << node->content->first << " ";
            if (node->right && !is_sentinel(node->right))
            {
                display_self(node->right);
            }
        }

        int get_max_depth(node_pointer root)
		{
			if (!root || is_sentinel(root))
				return 0;
			int depth1 = get_max_depth(root->left);
			int depth2 = get_max_depth(root->right);
			return depth1 > depth2 ? depth1 + 1 : depth2 + 1;
		}

        void get_nodes_by_depth(std::vector<std::vector<node_pointer> > & nodes, node_pointer node = 0, int depth = 0)
		{
			if (!node && depth == 0)
			{
				node = _root;
				if (!node)
					return ; //empty
			}
			if (node && node->left && !is_sentinel(node->left))
				get_nodes_by_depth(nodes, node->left, depth + 1);
			else if ((size_t)(depth + 1) < nodes.size())
				get_nodes_by_depth(nodes, 0, depth + 1);
			nodes[depth].push_back(node);
			if (node && node->right && !is_sentinel(node->right))
				get_nodes_by_depth(nodes, node->right, depth + 1);
			else if ((size_t)(depth + 1) < nodes.size())
				get_nodes_by_depth(nodes, 0, depth + 1);
		}

		size_t sp2(int x) //sum of power of 2
		{
			if (x == 0) return 0;
			size_t r = 1;
			while (--x > 0)
				r += pow(2, x);
			return r;
		}
        public:
		void print_tree_ascii()
		{
			int elem_size = 1;
			int depth = get_max_depth(_root);
			std::vector<std::vector<node_pointer> > v;
			for (int i = 0; i < depth; ++i)
				v.push_back(std::vector<node_pointer>()); //filing v with depth
			get_nodes_by_depth(v);
			int i = depth - 1;
			std::string padding;
			for (typename std::vector<std::vector<node_pointer> >::iterator i1 = v.begin(); i1 != v.end(); ++i1)
			{
				padding.append(sp2(i) * elem_size, ' ');
				std::cout << padding;
				padding.clear();
				padding.append(sp2(i + 1) * elem_size, ' ');
				for (typename std::vector<node_pointer>::iterator i2 = (*i1).begin(); i2 != (*i1).end(); ++i2)
				{
					if (*i2)
					{
						if ((*i2)->color == RED)
							std::cout << "\033[31m";
						else
							std::cout << "\033[37m";
						std::cout << (*i2)->content->first << padding;
					}
					else
						std::cout << "\033[37m " << padding;
				}
				std::cout << std::endl;
				--i;
				padding.clear();
			}
			std::cout << "\033[0m" << std::endl; //back to normal
		}
    };
}

#endif /* ************************************************************* MAP_HPP */
