#include "RPN.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	RPN rpn;
	int result;
	//add canonical form;
	//change error messages;
	//can we get negative ints? or just nbr between 0-10?
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
