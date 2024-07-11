#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <list>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe p;
	try {
		p.parse_input(argc, argv);
		p.fordJohnson_sort();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
