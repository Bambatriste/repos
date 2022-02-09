#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << "test with a mutantstack :" << std::endl;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	++rit;
	--rit;
	++it;
	--it;
	std::cout << "display with reverse iterators" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	//displays 0 737 5 3 in reverse order (because it s a last in first out behavior : LIFO)
	std::cout << "display with normal operators :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl << std::endl;
	std::cout << "test with a list instead :" <<std::endl;


	std::list<int>	test_list;

	test_list.push_back(5);
	test_list.push_back(17);

	std::cout << test_list.back() << std::endl;

	test_list.pop_back();

	std::cout << test_list.size() << std::endl;

	test_list.push_back(3);
	test_list.push_back(5);
	test_list.push_back(737);
	test_list.push_back(0);

	std::list<int>::iterator itl = test_list.begin();
	std::list<int>::iterator itel = test_list.end();
	std::list<int>::reverse_iterator ritl = test_list.rbegin();
	std::list<int>::reverse_iterator ritel = test_list.rend();

	++ritl;
	--ritl;
	++itl;
	--itl;
	std::cout << "test with reverse iterators for list" << std::endl;
	while (ritl != ritel)
	{
		std::cout << *ritl << std::endl;
		++ritl;
	}
	std::cout << "test with normal iterators for list" << std::endl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}



	return 0;
}


