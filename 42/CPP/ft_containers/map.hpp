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
        size_type size() const { return _size; }
		size_type max_size() const { return _node_allocator.max_size(); }

        //explicit map( const Compare& comp, const Allocator& alloc = Allocator() );


        //MODIFIERS



        void erase( iterator pos )
        {
            _allocator.destroy(pos);
        }

        // ft::pair<iterator, bool> insert( const value_type& value )
        // {
        //     insert_node(value);
        // }

        //ACCESSORS

        iterator begin()
        {return (iterator(get_leftmost_node()));}

        const_iterator begin() const
        {
            if (this->empty())
				return this->end();
            return (const_iterator(get_leftmost_node()));}

        iterator end()
        {return(iterator(_end));}

        const_iterator end() const
        {return(const_iterator(_end));}

        reverse_iterator rbegin()
        {
            if (this->empty())
				return this->rend();
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            if (this->empty())
				return this->rend();
            return const_reverse_iterator(end());}

        reverse_iterator rend()
        {return reverse_iterator(begin());}

        const_reverse_iterator rend() const
        {return const_reverse_iterator(begin());}

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
    
        public:



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
                        //update_end_node();
                        //rb_insert_fixup(tmp->right);
                        rotate_colorflip(tmp->left);
                        //recolor_rotate(tmp->left);
                        return ft::make_pair(iterator(tmp->left), true);
                    }
                    tmp = tmp->left;
                }
                else if (_comp(tmp->content->first, content.first))
                {
                    if (!tmp->right || is_sentinel(tmp->right))
                    {
                        tmp->right = create_node(content, tmp);
                        //rb_insert_fixup(tmp->right);
                        //recolor_rotate(tmp->right);
                        rotate_colorflip(tmp->right);
                        update_end_node();
                        
                        return ft::make_pair(iterator(tmp->right), true);
                    }
                    tmp = tmp->right;
                }
            }
            return ft::make_pair(iterator(tmp), false);
        }

        void m_rotate(node_pointer x, int side) //x = parent
        {

            node_pointer y = x->child[1 - side]; // set y
            x->child[1 - side] = y->child[side]; // turn y’s left subtree into x’s right subtree
            if (y->child[side] != 0)
                y->child[side]->parent = x;
            y->parent = x->parent;
            if (x->parent == NULL)
                _root = y;
            else if (x == x->parent->child[side])
                x->parent->child[side] = y;
            else
                x->parent->child[1 - side] = y;
            y->child[side] = x;
            x->parent = y;
        }

        void    rotate_colorflip(node_pointer node)
        {
            node_pointer parent = node->parent;
            node_pointer grandparent;
            node_pointer aunt;

            while (parent != 0)
            {
                if (parent->color == BLACK)
                    return;
                //parent is black , we end
                if ((grandparent = parent->parent) == 0)
                {
                    parent->color = BLACK;
                    return;
                }
                // grandparent is root , thus we can just set parent to black and end
                int side = node_side(parent);
                aunt = grandparent->child[1 - side];
                if (!aunt ||  is_sentinel(aunt) || aunt->color == BLACK)
                {
                    if (node == parent->child[1 - side]) //node isn t same side as grand parent so we rotate
                    {
                        m_rotate(parent, side);
                        node = parent;
                        parent = grandparent->child[side]; 
                    }
                    m_rotate(grandparent, 1 - side);
                    parent->color = BLACK;
                    grandparent->color = RED;
                    return;
                }
                grandparent->color = RED;
                parent->color = BLACK;
                aunt->color = BLACK;
                node = grandparent;
                parent = parent->parent;
            }
        }

        // void recolor_rotate(node_pointer node)
		// {
		// 	node_pointer uncle, parent, grandparent;

		// 	parent = node->parent;
		// 	do
		// 	{
		// 		if (parent->color == BLACK)
		// 			return ;
		// 		//parent is RED
		// 		if ((grandparent = parent->parent) == 0)
		// 		{
		// 			parent->color = BLACK;
		// 			return ;
		// 		}
		// 		//parent is RED and grandparent exists
		// 		int side = node_side(parent);
		// 		uncle = grandparent->child[1 - side];
		// 		if (!uncle || is_sentinel(uncle) || uncle->color == BLACK)
		// 		{
		// 			if (node == parent->child[1 - side])
		// 			{
		// 				m_rotate(parent, side);
		// 				node = parent;
		// 				parent = grandparent->child[side];
		// 			}
		// 			m_rotate(grandparent, 1 - side);
		// 			parent->color = BLACK;
		// 			grandparent->color = RED;
		// 			return ;
		// 		}
		// 		//parent and uncle are RED
		// 		parent->color = BLACK;
		// 		uncle->color = BLACK;
		// 		grandparent->color = RED;
		// 		node = grandparent;
		// 	} while ((parent = node->parent) != 0);
		// }

        void rb_insert_fixup(node_pointer child)
        {
            node_pointer y;
            while (child->parent->color == RED)
            {
                if (child->parent == child->parent->parent->left)
                {
                    y = child->parent->parent->right;
                    if (y->color == RED)
                    {
                        child->parent->color = BLACK;
                        y->color = BLACK;
                        child->parent->parent->color = RED;
                        child = child->parent->parent;
                    }
                }
                else if (child == child->parent->right)
                {
                    child = child->parent;
                    m_rotate(child, LEFT);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                m_rotate(child->parent->parent, RIGHT);
            }
            _root->color = BLACK;
        }


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

        public:
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

        private:

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
