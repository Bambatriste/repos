//define STD

#ifdef STD
 #include <vector>
 #include <map>
 #include <stack>
 //#include <type_traits>
 namespace ft = std;
#else
 #include "vector.hpp"
//#include "map.hpp"
//#include "stack.hpp"
 #include "pair.hpp"
 #include "is_integral.hpp"
 #include "enable_if.hpp"
 #include "iterators_traits.hpp"
 #include "reverse_iterator.hpp"
 #include "lexicographical_compare.hpp"
 #include "vector.hpp"
#endif


#include <utility>
#include <string>
#include <iostream>

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

	// std::cout << std::boolalpha;
 	//std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	// std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	// std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	// std::cout << "long int: " << ft::is_integral<long int>::value << std::endl;

	/*********************************** ENABLE_IF TESTS **********************************/
	

	/*********************************** VECTOR TESTS *************************************/


	const std::allocator<int> allocator_int;

	ft::vector<int> vector1;
	ft::vector<int> vector2(allocator_int);

	vector2.push_back(100);
	std::cout << vector2.back();
	vector2.push_back(42);
	std::cout << vector2.back();
	vector2.pop_back();
	std::cout << vector2.back();
	std::cout << vector2.size();
	std::cout << vector2.capacity();
	//display_vector(vector2);
	vector2.reserve(99);
	//display_vector(vector2);
	// std::cout << vector2.size();
	// std::cout << vector2.capacity();
	vector2.push_back(43);
	vector2.push_back(44);
	vector2.push_back(45);
	vector2.push_back(46);
	vector2.push_back(47);
	vector2.push_back(48);
	//display_vector(vector2);
	int pouet = 36;
	vector2.insert(vector2.begin() + 2, pouet); //segv if begin is out of range

	display_vector(vector2);


}