#include "Harl.hpp"
#include <iostream>
#include <string>
int main(int argc, char **argv)
{
	Harl harl;
	std::string level;

	if (argc != 2)
	{
		std::cout << "Invalid number or args" << std::endl;
		return 1;
	}
	level = argv[1];
	harl.complain(level);
}
