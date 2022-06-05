#ifndef NODE_HPP
# define NODE_HPP


# include "pair.hpp"

enum Node_color { BLACK, RED };

# define LEFT 0
# define RIGHT 1
# define left  child[LEFT]
# define right child[RIGHT]
# define is_sentinel(node_pointer) (node_pointer->content == 0 ? true : false)
# define node_side(node_pointer) (node_pointer == node_pointer->parent->right ? RIGHT : LEFT)

namespace ft {

	template <class T1, class T2>
	struct Node
	{
		typedef typename 	ft::pair<const T1,T2>* 		pointer;
		typedef				Node*						node_pointer;
		typedef				Node&						node_reference;

		pointer content;
		node_pointer parent;
		Node_color color;
		node_pointer child[2];
	};
}


#endif /* ************************************************************* NODE_HPP */
