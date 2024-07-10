#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

PmergeME::PmergeME() {};



void print_pairs(const std::vector<std::pair<int, int> >& pairs) {
    std::vector<std::pair<int, int> >::const_iterator it_pairs;
    std::cout << "Pairs:" << std::endl;
    for (it_pairs = pairs.begin(); it_pairs != pairs.end(); ++it_pairs) {
        std::cout << "(" << it_pairs->first << ", " << it_pairs->second << ") ";
    }
    std::cout << std::endl;
}

void print_main(const std::vector<int>& main) {
    std::vector<int>::const_iterator it_main;
    std::cout << "Main:" << std::endl;
    for (it_main = main.begin(); it_main != main.end(); ++it_main) {
        std::cout << *it_main << " ";
    }
    std::cout << std::endl;
}

void print_pending(const std::vector<std::pair<int, size_t> >& pending) {
    std::vector<std::pair<int, size_t> >::const_iterator it_pending;
    std::cout << "Pending:" << std::endl;
    for (it_pending = pending.begin(); it_pending != pending.end(); ++it_pending) {
        std::cout << "(" << it_pending->first << ", b" << it_pending->second << ") ";
    }
    std::cout << std::endl;
}
void print_insert_list(const std::vector<std::pair<int, size_t> >& insert_lst) {
    std::vector<std::pair<int, size_t> >::const_iterator it_insert_lst;
    std::cout << "insert_lst:" << std::endl;
    for (it_insert_lst = insert_lst.begin(); it_insert_lst != insert_lst.end(); ++it_insert_lst) {
        std::cout << "(" << it_insert_lst->first << ", b" << it_insert_lst->second << ") ";
    }
    std::cout << std::endl;
}
void PmergeME::parse_input(int argc, char **argv) {

	int number;
	if (argc == 1)
		throw std::runtime_error("No args provided");
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
		pairs.push_back(std::make_pair(vec[vec.size() - 1], (vec.size() / 2) + 1));
}

void fill_vectors( std::vector<int> &main, std::vector<std::pair<int, size_t > >&pending, std::vector<std::pair<int, int> > &pairs, int vec_size)
{

	std::vector<std::pair<int, int> >::iterator final_pos =  pairs.end() - (vec_size % 2);
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != final_pos; it++)
	{
		main.push_back(it->second);
		pending.push_back(std::make_pair(it->first, main.size())); //store the inital b order
	}
	if (final_pos == (--pairs.end()))
		pending.push_back(std::make_pair((--pairs.end())->first, (--pairs.end())->second));
	main.insert(main.begin(), pending.begin()->first);
	pending.erase(pending.begin());
}

bool compare(std::pair<int, int> &a, std::pair<int, int> &b)
{
	return a.second < b.second;
}
unsigned long getNextJacobstal(unsigned long prev, unsigned long prevPrev) {
	return prev + 2 * prevPrev;
}
void get_Jacobstal_insertion_list(const std::vector<std::pair<int, size_t> > &pending, std::vector<std::pair<int , size_t> > &insert_list , int pending_lst_size)
{
	unsigned long prev_jacobstal = 1;
	unsigned long cur_jacobstal = 1;
	unsigned long prev_temp;
	unsigned long cur_b;
	std::cout <<"pending lst size = " <<pending_lst_size << std::endl;
	while (cur_jacobstal <= static_cast<unsigned long>(pending_lst_size))
	{
		prev_temp = prev_jacobstal;
		prev_jacobstal = cur_jacobstal;
		cur_jacobstal = getNextJacobstal(cur_jacobstal, prev_temp);
		cur_b = cur_jacobstal ;
		// std::cout << "cur_b = " << cur_b << std::endl;
		std::cout << "prev jacobstal = " << prev_jacobstal << std::endl;
		std::cout << "cur jacobstal = " << cur_jacobstal << std::endl;
		std::cout << "pending size to compare = " <<static_cast<unsigned long>(pending_lst_size) << std::endl;
		while (cur_b > static_cast<unsigned long>(pending_lst_size))
		{
			std::cout << "decrementing b , b before = "<<cur_b << std::endl;
			cur_b--;
			std::cout << "b after = " << cur_b << std::endl;
		}

		while (cur_b > prev_jacobstal)
		{
			std::cout << "cur_b = " << cur_b << std::endl;
			insert_list.push_back(pending.at(cur_b - 2));
			cur_b--;
		}
	}
}

void print_vectors(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& main, const std::vector<std::pair<int, size_t> >& pending, int vec_size) {
    std::vector<std::pair<int, int> >::const_iterator it_pairs;
    std::vector<int>::const_iterator it_main;
    std::vector<std::pair<int, size_t> >::const_iterator it_pending;

    std::cout << "Pairs:" << std::endl;
    for (it_pairs = pairs.begin(); it_pairs != --pairs.end(); ++it_pairs) {
		std::cout << "(" <<it_pairs->first << ", " << it_pairs->second << ") ";
    }
	if (vec_size % 2 == 0)
		std::cout << "(" << (--pairs.end())->first << ", " << (--pairs.end())->second << ") ";
	else
		std::cout << "(" << (--pairs.end())->first << ", sizeOf pending list = " << (--pairs.end())->second << ") ";
    std::cout << std::endl;

    std::cout << "Main:" << std::endl;
    for (it_main = main.begin(); it_main != main.end(); ++it_main) {
        std::cout << *it_main << " ";
    }
    std::cout << std::endl;

    std::cout << "Pending:" << std::endl;
    for (it_pending = pending.begin(); it_pending != pending.end(); ++it_pending) {
        std::cout << "(" << it_pending->first << ", b" << it_pending->second << ") ";
    }
    std::cout << std::endl;
}
void PmergeME::merge_insert_vec()
{
	//compare with size of main - index of b -1;
	std::vector<std::pair<int, int> >pairs;
	std::vector<int> main;
	std::vector<std::pair<int, size_t> > pending;
	std::vector<std::pair<int , size_t> > insert_list;
	if (_vec.size() == 1)
	{
		std::cout << _vec[0] << std::endl;
		return;
	}
	make_pairs(_vec, pairs);
	std::sort(pairs.begin(), (_vec.size() % 2 == 0 ? pairs.end(): --pairs.end()), compare);
	fill_vectors(main, pending, pairs, _vec.size());
	print_vectors(pairs, main, pending, _vec.size());
	get_Jacobstal_insertion_list(pending, insert_list , ( _vec.size() / 2) + (_vec.size() % 2));
	print_insert_list(insert_list);
}


