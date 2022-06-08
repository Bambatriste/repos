#ifndef MAP_HPP
# define MAP_HPP

#define BLACK 0
#define RED 1


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
        node_pointer    TNULL;

        public:

        //constructeurs :

        explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		: 
        _allocator(alloc),
        _node_allocator(alloc),
        _end(0),
        _size(0),
        _comp(comp)
		{
            TNULL = new node;
            TNULL->color = BLACK;
            TNULL->left = TNULL;
            TNULL->right = TNULL;
            TNULL->parent = TNULL;
            _root = TNULL;
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
            new_node->left = TNULL;
            new_node->right = TNULL;
            new_node->parent = parent;
            new_node->color = RED;
            ++_size;
            return new_node;
        }

        void create_end_node()
        {
            _end = _node_allocator.allocate(1);
            _end->content = 0;
            _end->left = TNULL;
            _end->right = TNULL;
            _end->parent = TNULL;
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
            while (tmp->right != TNULL && (!is_sentinel(tmp->right)))
                tmp = tmp->right;

            return tmp;
        }

        node_pointer get_leftmost_node()
        {
            if (this->empty())
				return 0;
            node_pointer tmp = _root;
            while (tmp->left != TNULL && (!is_sentinel(tmp->left)))
                tmp = tmp->left;
            return tmp;
        }

        node_pointer tree_minimum(node_pointer x)
        {
            while (x->left != TNULL)
                x = x->left;
            return x;
        }

        node_pointer tree_maximum(node_pointer x)
        {
            while (x->right != TNULL && !is_sentinel(x->right))
                x = x->right;
            return x;
        }

        node_pointer in_order_successor(node_pointer node)
		{
			node_pointer successor = node->right;
			while (successor->left && successor->left != TNULL && !is_sentinel(successor->left))
				successor = successor->left;
			return successor;
		}
    
        public:


        pair<iterator, bool> insert(const value_type& content)
        {
            if (_root == TNULL)
            {
                _root = create_node(content, TNULL);
                _root->color = BLACK;
                update_end_node();
                return ft::make_pair(iterator(_root), true);
            }
            node_pointer tmp = _root;
            while (tmp != TNULL)
            {
                if (_comp(content.first, tmp->content->first))
                {
                    if (tmp->left == TNULL)
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
                    if (tmp->right == TNULL || is_sentinel(tmp->right))
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
                else
                    break;
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
            if (x->parent == TNULL)
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

            while (parent != TNULL)
            {
                if (parent->color == BLACK)
                    return;
                //if parent is black , we end
                if ((grandparent = parent->parent) == TNULL)
                {
                    parent->color = BLACK;
                    return;
                }
                // grandparent is root , thus we can just set parent to black and end
                int side = node_side(parent); // parent side
                aunt = grandparent->child[1 - side];
                if (aunt == TNULL ||  is_sentinel(aunt) || aunt->color == BLACK)
                {
                    if (node == parent->child[1 - side]) //node isn t same side as parent so we rotate
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
                parent = node->parent;
            }
            _root->color = BLACK;
        }
        public:

        void erase( iterator pos );
        void erase( iterator first, iterator last );
        size_type erase( const Key& key )
        {
            node_pointer node_test = _root;
            while (node_test != TNULL && !is_sentinel(node_test))
            {
                if (_comp(key, node_test->content->first))
					node_test = node_test->left;
				else if (_comp(node_test->content->first, key))
					node_test = node_test->right;
                else
                {
                    //_end->parent->right = 0;
                    std::cout << "node value :" << key << std::endl;
                    rb_delete(node_test);
                    return (1);
                }
            }
            return (0);
        }

        void rb_transplant(node_pointer u, node_pointer v)
        {

            if (u->parent == TNULL)
                _root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else 
                u->parent->right = v;
            v->parent = u->parent;
        }

        void    rb_delete(node_pointer z)
        {
            node_pointer y = z;
            node_pointer x;

            bool y_original_color = y->color;

            if (z->left == TNULL)
            {   
                x = z->right;
                rb_transplant(z, z->right);
            }
            else if (z->right == TNULL)
            {
                x = z->left;
                rb_transplant(z, z->left);
            }
            else
            {
                y = tree_minimum(z->right); // y never has a left child.
                x = y->right;
                y_original_color = y->color;
                if (y->parent == z)
                    x->parent = y;
                else
                {
                    rb_transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y; // r->y->x becomes y->r->x 
                }
                rb_transplant(z, y); //delete z and replace it by y
                y->left = z->left; // transplant z->left into y
                y->left->parent = y;
                y->color = z->color;
            }
            if (y_original_color == BLACK)
                 deleteFix(x);
            delete_node(z);
        }

        void deleteFix(node_pointer x) 
        {
            node_pointer s;
            while (x != _root && x->color == BLACK) 
            {
                if (x == x->parent->left) 
                {
                    s = x->parent->right;
                    if (s->color == RED) 
                    {
                        s->color = BLACK;
                        x->parent->color = RED;
                        m_rotate(x->parent, LEFT);
                        s = x->parent->right;
                    }
                    if (s->left->color == BLACK && s->right->color == BLACK)
                    {
                        s->color = RED;
                        x = x->parent;
                    }
                    else 
                    {
                        if (s->right->color == BLACK) 
                        {
                            s->left->color = BLACK;
                            s->color = RED;
                            m_rotate(s, RIGHT);
                            s = x->parent->right;
                        }
                        s->color = x->parent->color;
                        x->parent->color = BLACK;
                        s->right->color = BLACK;
                        m_rotate(x->parent, LEFT);
                        x = _root;
                    }
                } 
                else 
                {
                    s = x->parent->left;
                    if (s->color == RED) 
                    {
                        s->color = BLACK;
                        x->parent->color = RED;
                        m_rotate(x->parent, RIGHT);
                        s = x->parent->left;
                    }
                    if (s->right->color == BLACK && s->left->color == BLACK) 
                    {
                        s->color = RED;
                        x = x->parent;
                    } 
                    else 
                    {
                        if (s->left->color == BLACK) 
                        {
                            s->right->color = BLACK;
                            s->color = RED;
                            m_rotate(s, LEFT);
                            s = x->parent->left;
                        }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    m_rotate(x->parent, RIGHT);
                    x = _root;
                    }
                }
            }
            x->color = BLACK;
        }

        void    delete_node(node_pointer node)
        {
            if (node->content)
            {
                _allocator.destroy(node->content);
                _allocator.deallocate(node->content, 1);
            }
            _node_allocator.destroy(node);
            _node_allocator.deallocate(node, 1);
            --_size;
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

          void printTree() {
            if (_root) {
            printHelper(this->_root, "", true);
            }
        }


          void printHelper(node_pointer root, std::string indent, bool last) {
            if (root != TNULL) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            } else {
                std::cout << "L----";
                indent += "|  ";
            }

            std::string sColor;
            if( root->color == RED)
                sColor = "RED";
            else if (root->color == BLACK)
                sColor ="BLACK";
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
            }
        }

        public:
        void    display_self(node_pointer node = 0)
        {
            if (!node)
            {
                node = _root;
                if (node == TNULL)
                    return;
            }
            if (node->left != TNULL && !is_sentinel(node->left))
            {
                display_self(node->left);
            }
            std::cout << node->content->first << " ";
            if (node->right != TNULL && !is_sentinel(node->right))
            {
                display_self(node->right);
            }
        }

        void print_node(node_pointer node)
		{
			if (node->color == RED)
				std::cout << "\033[31m";
			else
				std::cout << "\033[30m";
			std::cout << node->content->first;
		}

		int get_max_depth(node_pointer root)
		{
			if (!root || root == TNULL|| is_sentinel(root))
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
			if (node && !is_sentinel(node->left))
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
