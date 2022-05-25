#ifndef NODE_HPP
# define NODE_HPP


# include "pair.hpp"

//node contains : bool (red/black); T value; node * leftchild; node *rightchild;

namespace ft {

	template <class T1, class T2>
	struct Node
	{
		typedef typename 	ft::pair<T1,T2>* 	pointer;
		typedef				Node*				node_pointer;
		typedef				Node&				node_reference;

		pointer content;
		node_pointer parent;
		bool color;
		node_pointer child[2];
	};
}


#endif /* ************************************************************* NODE_HPP */
