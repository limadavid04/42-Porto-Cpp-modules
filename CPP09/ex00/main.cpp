#include "BitcoinExchange.hpp"
#include <iostream>

int main (int argc, char **argv)
{

	BitcoinExchange ex;
	if (argc != 2)
	{
		std::cerr << "Wrong number of args" << std::endl;
		return (1);
	}
	std::string file = argv[1];
	ex.convert(file);
	return (0);
}
