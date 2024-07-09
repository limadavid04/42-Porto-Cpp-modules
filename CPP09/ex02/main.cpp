#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <list>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeME p;
	p.parse_input(argc, argv);
	p.merge_insert_vec();
}
