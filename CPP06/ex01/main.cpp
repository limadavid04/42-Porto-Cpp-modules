#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data data;
	Data * data_ptr;

	uintptr_t addr;
	std::cout << "Data adress = " << &data << std::endl;
	addr = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(addr);
	std::cout << "data_ptr adress = " << data_ptr << std::endl;
}
