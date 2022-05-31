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
    template<class Key,
             class T,
            class Compare = std::less<Key>,
            class Allocator = std::allocator<ft::pair<const Key, T> > 
            >
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
        _comp(comp)
		{
			create_end_node();
		}

        // capacity

        bool empty() const { return _size == 0; }

        //explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

        //private:

        node_pointer create_node(const value_type &content, node_pointer parent)
        {
            node_pointer new_node = _node_allocator.allocate(1);
            new_node->content = _allocator.allocate(1);
            _allocator.construct(new_node->content, content);
            new_node->left = 0;
            new_node->right = 0;
            new_node->parent = parent;
            new_node->color = BLACK;
            ++_size;
            std::cout << "root node :" << std::endl;
            std::cout << new_node->content->second << std::endl;
            std::cout << new_node->right << std::endl;
            std::cout << new_node->left << std::endl;
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

        void    insert_node(const value_type& content)
        {
            if (!_root)
            {
                _root = create_node(content, 0);
                _root->color = BLACK;
                update_end_node();
                std::cout << "root node after :" << std::endl;
                std::cout << _root->content->second << std::endl;
                std::cout << _root->right << std::endl;
                std::cout << _root->left << std::endl;
                std::cout << "test1" << std::endl;
                return ;
                
            }
            node_pointer tmp = _root;
            while (tmp)
            {
                std::cout << "test2" << std::endl;
                if (_comp(content.first, tmp->content->first))
                {
                    if (!tmp->left)
                    {
                        std::cout << tmp->content << std::endl;
                        std::cout << "no tmp left" << std::endl;
                        tmp->left = create_node(content, tmp);
                        update_end_node();
                        return;
                    }
                    tmp = tmp->left;
                }
                else
                {
                    if (!tmp->right || is_sentinel(tmp->right))
                    {
                        std::cout << tmp->content << std::endl;
                        std::cout << tmp->right << std::endl;
                        std::cout << "no tmp right" << std::endl;
                        tmp->right = create_node(content, tmp);
                        update_end_node();
                        return;
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

    //iterators
    //accessor to display this beauty
    // binary tree iterator
    // add red black rules


#endif /* ************************************************************* MAP_HPP */
