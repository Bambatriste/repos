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

namespace ft 
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {

        public:
		// types:
		typedef Key                                             key_type;
		typedef T                         			            mapped_type;
        typedef ft::pair<const Key, T>                          value_type;                               
		typedef std::size_t	        							size_type; 
		typedef std::ptrdiff_t									difference_type;
		typedef Compare										    key_compare;
		typedef Allocator										allocator_type;
        typedef value_type&                                     reference;
        typedef const value_type&                               const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		//typedef 		LEGACY BIDIR ITER TO VALUETYPE			iterator;
		//typedef       CONST LEGACY BIDIR ITER TO VALUETYPE	const_iterator;
		//typedef ft::reverse_iterator<iterator>					reverse_iterator;
		//typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;


        //todo :


        // node for binary tree
        // binary tree constructor
        // binary tree iterator
        // add red black rules
        
    };
}


#endif /* ************************************************************* MAP_HPP */