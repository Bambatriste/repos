#include "pair.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "vector.hpp"


#include <utility>
#include <string>
#include <iostream>
#include <vector>


template<class T>
void display_vector(ft::vector<T> vector)
{
	std::cout << std::endl;
	std::cout << "vector display" << std::endl;
	for (unsigned int i = 0; i < vector.size(); i++)
	{std::cout << vector[i] << std::endl;}
}



int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	//default constructor

	/*********************************** PAIR TESTS **********************************/

	// std::pair<int, std::string>p1;
	// ft::pair<int , std::string>p2;

	// std::cout << p1.first << std::endl;
	// std::cout << p1.second << std::endl;

	// std::cout << p2.first << std::endl;
	// std::cout << p2.second << std::endl;

	// // assignation constructor

	// std::pair <int , std::string>p3(42,"abc");

	// std::cout << p3.first << std::endl;
	// std::cout << p3.second << std::endl;

	// ft::pair <int, std::string>p4(42, "abc");

	// std::cout << p4.first << std::endl;
	// std::cout << p4.second << std::endl;

	// // copy constructor

	// std::pair <int , std::string>p6(p3);

	// std::cout << p6.first << std::endl;
	// std::cout << p6.second << std::endl;

	// ft::pair <int , std::string>p7(p4);

	// std::cout << p7.first << std::endl;
	// std::cout << p7.second << std::endl;

	// // operator=

	// p6=p1;

	// std::cout << p6.first << std::endl;
	// std::cout << p6.second << std::endl;

	// p7 = p2;

	// std::cout << p7.first << std::endl;
	// std::cout << p7.second << std::endl;

	// //comparison operators :

	// // ==

	// std::cout << (p2 ==p7) << std::endl;
	// //p7.first = 2;
	// //p7.second = 33;
	// std::cout << (p2 ==p7) << std::endl;

	// // !=

	// std::cout << (p2 !=p7) << std::endl;
	// //p7.first = 2;
	// //p7.second = 33;
	// std::cout << (p2 !=p7) << std::endl;



	// p2.first = 0;
	// p7.first = 0;
	// p2.second = "abc";
	// p7.second = "abc";

	// std::cout << "== :" << (p2 == p7) << std::endl;
	// std::cout << "!= :" << (p2 != p7) << std::endl;
	// std::cout << "< :" << (p2 <p7) << std::endl;
	// std::cout << "<= :" << (p2 <=p7) << std::endl;
	// std::cout << "> :" << (p2 >p7) << std::endl;
	// std::cout << ">= :" << (p2 >=p7) << std::endl;


	// std::pair<int, int> p9 = std::make_pair(12,13);

	// std::cout << p9.first << std::endl;
	// std::cout << p9.second << std::endl;


	// ft::pair<int, int> p10 = ft::make_pair(12,13);

	// std::cout << p10.first << std::endl;
	// std::cout << p10.second << std::endl;


	/*********************************** IS INTEGRAL TESTS **********************************/

	std::cout << std::boolalpha;
 	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	std::cout << "long int: " << ft::is_integral<long int>::value << std::endl;

	/*********************************** ENABLE_IF TESTS **********************************/
	

	/*********************************** VECTOR TESTS *************************************/


	const std::allocator<int> allocator_int;

	std::vector<int> std_default_int_construct;
	ft::vector<int> ft_default_int_construct;

	std::vector<int> std_alloc1(allocator_int);
	ft::vector<int> ft_alloc1(allocator_int);

	ft_alloc1.push_back(100);
	std::cout << ft_alloc1.back();
	ft_alloc1.push_back(42);
	std::cout << ft_alloc1.back();
	ft_alloc1.pop_back();
	std::cout << ft_alloc1.back();
	std::cout << ft_alloc1.size();
	std::cout << ft_alloc1.capacity();
	display_vector(ft_alloc1);
	ft_alloc1.reserve(99);
	display_vector(ft_alloc1);
	// std::cout << ft_alloc1.size();
	// std::cout << ft_alloc1.capacity();
	ft_alloc1.push_back(43);
	ft_alloc1.push_back(44);
	ft_alloc1.push_back(45);
	ft_alloc1.push_back(46);
	ft_alloc1.push_back(47);
	ft_alloc1.push_back(48);
	display_vector(ft_alloc1);
	int pouet = 36;
	ft_alloc1.insert(ft_alloc1.begin(), pouet); //segv if begin is out of range
	display_vector(ft_alloc1);












}