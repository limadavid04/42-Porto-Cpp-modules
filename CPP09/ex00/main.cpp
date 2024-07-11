#include "BitcoinExchange.hpp"
#include <iostream>

int main (int argc, char **argv)
{

	//ADD CANONICAL FORM;
	BitcoinExchange ex;
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string file = argv[1];
	try {
		ex.convert(file);
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
