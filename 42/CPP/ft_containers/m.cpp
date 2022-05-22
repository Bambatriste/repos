//#define STD

#ifdef STD
 #include <vector>
 #include <map>
 #include <stack>
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

// template<class T>
// void wrapper_insert(ft::vector<T>& vect, size_t count, T& value) {
// 	std::cout << "capacity before insert: " << vec.capacity();
// 	std::cout << "size before insert: " << vect.size();
// 	v.insert(count, value);
// 	std::cout << "capacity before insert: " << vec.capacity();
// 	std::cout << "size before insert: " << vect.size();
// }

class Observable {
	public:
		int _data;
		Observable() { _data = 0; std::cout << "Instance of Observable created." << std::endl; }
		Observable(int data): _data(data) { std::cout << "Instance of Observable created." << std::endl; }
		Observable(Observable const & src) { *this = src; }
		~Observable() { std::cout << "Instance of Observable destroyed." << this->_data << std::endl; }
		Observable &operator=(Observable const &rhs) { _data = rhs._data; return *this; }
};
std::ostream &operator<<(std::ostream & os, const Observable &obs) {
	os << obs._data;
	return os;
}

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
 	// std::cout << "char: " << ft::is_integral<char>::value << std::endl;
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
	//vector2.reserve(99);
	//display_vector(vector2);
	// std::cout << vector2.size();
	// std::cout << vector2.capacity();
	vector2.push_back(43);
	vector2.push_back(44);
	vector2.push_back(45);
	vector2.push_back(46);
	vector2.push_back(47);
	vector2.push_back(48);
	display_vector(vector2);

	

	ft::vector<int>::iterator insert_test = vector2.insert(vector2.begin() + 2, 36); //segv if begin is out of range , but std too
	std::cout << "return value for insert test : " << *insert_test << std::endl;



	vector2.insert(vector2.begin(), 5, 77);



	//  std::cout <<  "before insert capacity :" << vector2.capacity() << std::endl;
	// std::cout <<  "before insert size :" << vector2.size() << std::endl;

	vector2.insert(vector2.begin() + 2, 5, 33);

	// std::cout <<  "after insert capacity :" << vector2.capacity() << std::endl;
	// std::cout <<  "after insert size :" << vector2.size() << std::endl;

	
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector1.push_back(4);
	vector1.push_back(5);
	vector1.push_back(6);
	vector1.push_back(7);
	vector1.push_back(8);
	vector1.erase(vector1.begin());


	//ft::vector<int>::iterator test = vector1.erase(vector1.begin() +2, vector1.begin() + 4);

	
	//std::cout << "return value for erase : " << *test << std::endl;
	//vector2.resize(36, 0); // problem due to insert when resizing to bigger (invalid write : 1)
	//std::cout <<  "before insert capacity : :" << vector2.capacity() << std::endl;
	//std::cout <<  "before insert size :" << vector2.size() << std::endl;


	// std::cout <<  "before insert size : :" << vector2.size() << std::endl;
	// std::cout <<  "before insert capacity : :" << vector2.capacity() << std::endl;
	// std::cout << "number of elements to add : " << vector1.end() - vector1.begin() << std :: endl;
	// display_vector(vector2);
	vector2.insert(vector2.begin(), vector1.begin(), vector1.end()); // problem for erase and insert if vector1.end() + 1 probably just undefined behavior
	// std::cout <<  "after insert capacity : :" << vector2.capacity() << std::endl;
	// std::cout <<  "after insert size : :" << vector2.size() << std::endl;


	//std::cout <<  "before resize size :" << vector2.size() << std::endl;
	//vector2.resize(36, 0);
	//std::cout <<  "after resize capacity : :" << vector2.capacity() << std::endl;
	//std::cout <<  "after resize size :" << vector2.size() << std::endl;
	
	display_vector(vector2);
	vector2.assign(4, 99);
	display_vector(vector2);

	Observable c1;
	Observable c2;

	ft::vector<Observable> vector3;
	const std::allocator<Observable> obs;
	ft::vector<Observable> vector4(obs);

	vector4.push_back(c1);
	vector4.push_back(c2);
	vector4.push_back(c1);

	vector3.push_back(c1);
	vector3.push_back(c2);

	vector3.insert(vector3.end(), c2);

	//std::cout <<  "before insert :" << vector3.capacity() << std::endl;
	//std::cout <<  "before insert size :" << vector3.size() << std::endl;
	vector3.insert(vector3.end(), 5, c2);

	//std::cout <<  "after insert capacity :" << vector3.capacity() << std::endl;
	//std::cout <<  "after insert  size :" << vector3.size() << std::endl;

	vector3.insert(vector3.begin() +1, vector4.begin(), vector4.end());

	display_vector(vector3);

	vector3.erase(vector3.begin());
	vector3.erase(vector3.begin(), vector3.end() - 1);
	
	//std::cout << ptr << std::endl;

//std::cout << "last vector 3 display" << std::endl;
	display_vector(vector3);
	//std::cout << "vector3 capacity :" << vector3.capacity() << std::endl;
	//std::cout << "vector3 size :" << vector3.size() << std::endl;

	//int i = 0;
	//while (i < 15)
	//{
	vector3.insert(vector3.begin(), 17, Observable(1));
	// std::cout << "vector 3 size before resize :" << vector3.size() <<  std::endl;
	// std::cout << "vector 3 capacity before resize :" << vector3.capacity() <<  std::endl;
	vector3.resize(33, Observable());
	// std::cout << "vector 3 size after resize :" << vector3.size() <<  std::endl;
	// std::cout << "vector 3 capacity after resize :" << vector3.capacity() <<  std::endl;

	
	
	display_vector(vector3);


	display_vector(vector1);
	display_vector(vector2);
	vector1.swap(vector2);
	display_vector(vector1);
	display_vector(vector2);
	//vector3.push_back(c1);
	//std::cout << "vector3 capacity :" << vector3.capacity() << std::endl;
	//std::cout << "vector3 size :" << vector3.size() << std::endl;



	//vector2.resize(36, 0);

	//vector3.reserve(200);

	//std::cout << vector4[0]<< std::endl;
	//std::cout << vector3[0]<< std::endl;
}