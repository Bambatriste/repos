#include <iostream>

int main()
{
	std::string hi = "HI THIS IS BRAIN";

	std::string *stringPTR = &hi;
	std::string &stringREF = hi;

	std::cout << "Original str adress : " << &hi << std::endl;
	std::cout << "string PTR :" << stringPTR << std::endl;
	std::cout << "string REF :" << &stringREF << std::endl;

	std::cout << "String using PTR: " << *stringPTR << std::endl;
	std::cout << "String using REF: " << stringREF << std::endl;
}
