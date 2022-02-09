#include "Array.hpp"

#include <iostream>
#include <string>

int
	main(void)
{

	std::cout << "trying to cause a segv on purpose but within a try catch" << std::endl;
	Array<int>	intArray1;
	try
	{
		for (int i = 0; i < 1; i++)
			std::cout << intArray1[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Array<int> intArray2(23);
	intArray2[0] = 12;
	intArray2[1] = -12;
	intArray2[2] = 33;
	intArray2[3] = -33;
	intArray2[4] = 42;

	std::cout << "Array2 display : " << std::endl;

	for (int i = 0; i < 5; i++)
		std::cout << intArray2[i] << std::endl;

	std::cout << "put array2 into array1 with = operator and display array1" << std::endl;
	intArray1 = intArray2;
	for (int i = 0; i < 5; i++)
		std::cout << intArray1[i] << std::endl;


	std::cout << "set array1[0] to 999" << std::endl;
	intArray1[0] = 999;
	std::cout << "array 1[0] new value : " << intArray1[0] << std::endl;
	std::cout << "array 2[0] keeps the same value : " << intArray2[0] << std::endl;

	std::cout << "copy of array2 into a new Array3" << std::endl;
	Array<int>intArray3(intArray2);
	std::cout << "display array3" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << intArray3[i] << std::endl;

	std::cout << "set array3[2] to 777" << std::endl;
	intArray3[2] = 777;
	std::cout << "array 3[2] new value : " << intArray3[2] << std::endl;
	std::cout << "array 2[2] keeps the same value : " << intArray2[2] << std::endl;

	std::cout << "use of member func size :" << std::endl;

	std::cout << intArray2.size() << std::endl;
	std::cout << intArray1.size() << std::endl;
	std::cout << intArray3.size() << std::endl;

	Array<const float>constArray(42);

	//constArray[1] = 33;
	/* can not assign to a const array*/


	return (0);
}
