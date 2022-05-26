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

namespace ft 
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {

        public:
		// types:
        typedef Key                                                         key_type;
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
        //typedef 		LEGACY BIDIR ITER TO VALUETYPE			            iterator;
        //typedef       CONST LEGACY BIDIR ITER TO VALUETYPE	            const_iterator;
        //typedef ft::reverse_iterator<iterator>					        reverse_iterator;
        //typedef ft::reverse_iterator<const_iterator>	                    const_reverse_iterator;
        typedef Node<key_type, mapped_type>                                 node;
        typedef node*                                                       node_pointer;
        typedef typename    allocator_type::template rebind<node>::other	alnode;

        //constructeurs :

        map()
        :
        _size(0),
        _node_allocator_(_node_allocator_),
        _allocator_(_allocator_),
        _root(0)
        {
            create_end_node();
        }

        // capacity

        bool empty() const { return _size == 0; }

        //explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

        private:

        alnode          _node_allocator_;
        allocator_type  _allocator_;
        node_pointer    _root;
        node_pointer    _end;
        size_type       _size;
        key_compare     _comp;

        node_pointer create_node( value_type &content,node_pointer parent)
        {
            node_pointer new_node = _node_allocator_.allocate(1);
            new_node->content = _allocator_.allocate(1);
            _allocator_.construct(new_node->content, content);
            new_node->left = 0;
            new_node->right = 0;
            new_node->parent = parent;
            new_node->color = BLACK;
            ++_size;
            return new_node;
        }

        void create_end_node()
        {
            _end = _node_allocator_.allocate(1);
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

        void    insert_node(const value_type& content)
        {
            if (!_root)
            {
                _root = create_node();
                _root->color = BLACK;
                update_end_node();
            }
            node_pointer tmp = _root;
            while (tmp)
            {
                if (_comp(content.first, tmp->content.first))
                {
                    if (!tmp->left)
                    {
                        tmp->left = create_node(content, tmp);
                    }
                    tmp = tmp->left;
                }
                else
                {
                    if (!tmp->right)
                    {
                        tmp->right = create_node(content, tmp);
                        update_end_node();
                    }
                    tmp = tmp->right;
                }
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
    };
}


    //todo :

    //insert function
    //accessor to display this beauty
    // binary tree iterator
    // add red black rules


#endif /* ************************************************************* MAP_HPP */
