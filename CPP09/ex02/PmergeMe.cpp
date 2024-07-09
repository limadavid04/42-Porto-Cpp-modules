#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

PmergeME::PmergeME() {};

void PmergeME::parse_input(int argc, char **argv) {

	int number;
	for (int i = 1; i < argc; i++)
	{
		//check for max or min_int
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				throw std::runtime_error("Invalid input");
		}
		number = std::atoi(argv[i]);
		_vec.push_back(number);
		_lst.push_back(number);
	}
}

void make_pairs(std::vector<int> vec, std::vector<std::pair<int, int > > &pairs)
{

	size_t sizeForSorting = vec.size() - (vec.size() % 2);

	for (size_t i = 0 ; i < sizeForSorting - 1; i+=2)
	{
		if(vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	if (vec.size() != sizeForSorting)
		pairs.push_back(std::make_pair(vec[vec.size() - 1], -1));

	// 		size_t sizeForSorting = vec.size() - (vec.size() % 2);

	// for (int i = 0 ; i < sizeForSorting - 1; i+=2)
	// {
	// 	if(vec[i] > vec[i + 1])
	// 		std::swap(vec[i], vec[i + 1]);
	// 	main.push_back(vec[i+1]);
	// 	std::vector<int>::iterator it = --vec.end();
	// 	pending.push_back(std::make_pair(vec[i], it));
	// }
	// if (vec.size() != 0)
	// 	pending.push_back(std::make_pair(vec[vec.size() - 1], --vec.end()));
}

void fill_vectors( std::vector<int> &main, std::vector<std::pair<int, std::vector<int>::iterator> > &pending, std::vector<std::pair<int, int> > &pairs)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it < pairs.end(); it++)
	{
		if (it->second == -1)
		{
			pending.push_back(std::make_pair(it->first, static_cast<std::vector<int>::iterator>(0)));
		}
		else
		{

			main.push_back(it->second);
			std::vector<int>::iterator pair_it = --main.end();
			pending.push_back(std::make_pair(it->first, pair_it));
		}
	}
	main.insert(main.begin(), pending.begin()->first);
	pending.erase(pending.begin());
}
bool compare(std::pair<int, int> &a, std::pair<int, int> &b)
{
	return a.second < b.second;
}
// void get_Jacobian_insertion_list(std::vector<std::pair<int, std::vector<int>::iterator> > &pending)
// {
// 	unsigned long jacobian;
// 	while
// }

void printVectors(const std::vector<int> &main, const std::vector<std::pair<int, std::vector<int>::iterator> > &pending) {
    std::cout << "Main vector values:" << std::endl;
    for (std::vector<int>::const_iterator it = main.begin(); it != main.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Pending vector values:" << std::endl;
    for (std::vector<std::pair<int, std::vector<int>::iterator> >::const_iterator it = pending.begin(); it != pending.end(); ++it) {
        std::cout << it->first << " ";
        if (it->second != main.end()) { // Check if the iterator points to a valid element
            std::cout << *(it->second); // Dereference the iterator to print the value it points to
        } else {
            std::cout << "end"; // Indicate that the iterator points to the end
        }
        std::cout << std::endl;
    }
}

void PmergeME::merge_insert_vec()
{
	std::vector<std::pair<int, int> >pairs;
	std::vector<int> main;
	std::vector<std::pair<int, std::vector<int>::iterator> > pending;

	make_pairs(_vec, pairs);
	std::sort(pairs.begin(), (pairs.size() % 2 == 0 ? pairs.end(): --pairs.end()), compare);
	fill_vectors(main, pending, pairs);
	printVectors(main, pending);
}


