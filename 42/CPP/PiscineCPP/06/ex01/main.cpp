#include <iostream>
#include <string>
#include <stdint.h>

#include "Data.hpp"


uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data		*data = new Data(42, "pouet");
	uintptr_t	raw;
	Data		*ptr;

	std::cout << *data << std::endl;
	raw = serialize(data);
	std::cout << raw << std::endl;
	ptr = deserialize(raw);
	std::cout << *ptr << std::endl;


	delete data;

	return (0);

}
