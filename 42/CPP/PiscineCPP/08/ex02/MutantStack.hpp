#include <stack>

template<typename T>
	class MutantStack : public std::stack<T>
	{
		public:
			MutantStack() {}
			MutantStack(const MutantStack<T>& src) { *this = src; }
			MutantStack<T>& operator=(const MutantStack<T>& rhs) 
			{
				this->c = rhs.c;
				return *this;
			}
			~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator cbegin() { return static_cast<const T>(this->c.begin()); }
	const_iterator cend() { return static_cast<const T>(this->c.end()); }

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin() { return static_cast<const T>(this->c.rbegin()); }
	const_reverse_iterator crend() { return static_cast<const T>(this->c.rend()); }

};