#include "RPN.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	RPN rpn;
	int result;
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number or args" << std::endl;
		return (1);
	}
	std::string expression = argv[1];
	try {
		result = rpn.convert(expression);
		std::cout << result << std::endl;
	} catch (std::exception  &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
