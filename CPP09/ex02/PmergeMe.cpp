#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
PmergeME::PmergeME() {};

template <typename Iterator, typename T>
Iterator binary_search_insert_position(Iterator begin, Iterator end, const T& value) {
    Iterator low = begin;
    Iterator high = end;

	// std::cout << "insertion distance = " << std::distance(begin, end) << std::endl;
    while (low < high) {
		// comp++;
        Iterator mid = low + (high - low) / 2;
        if (*mid < value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

template<typename T>
bool isSorted(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

void print_main(const std::vector<int>& main) {
    std::vector<int>::const_iterator it_main;
    std::cout << "Main:" << std::endl;
    for (it_main = main.begin(); it_main != main.end(); ++it_main) {
        std::cout << *it_main << " ";
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
	while (cur_jacobstal <= static_cast<unsigned long>(pending_lst_size))
	{
		prev_temp = prev_jacobstal;
		prev_jacobstal = cur_jacobstal;
		cur_jacobstal = getNextJacobstal(cur_jacobstal, prev_temp);
		cur_b = cur_jacobstal ;

		while (cur_b > static_cast<unsigned long>(pending_lst_size))
			cur_b--;
		while (cur_b > prev_jacobstal)
		{
			insert_list.push_back(pending.at(cur_b - 2));
			cur_b--;
		}
	}
}


void insert_list_in_main(std::vector<std::pair<int , size_t> > &insert_list, std::vector<int> &main, size_t a_size)
{
	std::vector<int>::iterator pos;
	for (std::vector<std::pair<int, size_t> >::iterator it = insert_list.begin(); it != insert_list.end(); it++)
	{
		if (it->second >= a_size)
			pos = binary_search_insert_position(main.begin(), main.end(), it->first);
		else
			pos = binary_search_insert_position(main.begin(), main.end() - (a_size - it->second+1), it->first);
		main.insert(pos, it->first);
	}
}

void PmergeME::merge_insert_vec()
{
	//compare with size of main - index of b -1;
	std::vector<std::pair<int, int> >pairs;
	std::vector<int> main;
	std::vector<std::pair<int, size_t> > pending;
	std::vector<std::pair<int , size_t> > insert_list;

	std::clock_t start = std::clock();
	if (_vec.size() == 1)
	{
		std::cout << _vec[0] << std::endl;
		return;
	}
	make_pairs(_vec, pairs);
	std::sort(pairs.begin(), (_vec.size() % 2 == 0 ? pairs.end(): --pairs.end()), compare);
	fill_vectors(main, pending, pairs, _vec.size());
	get_Jacobstal_insertion_list(pending, insert_list , ( _vec.size() / 2) + (_vec.size() % 2));
	insert_list_in_main(insert_list, main, _vec.size()/2);
	std::clock_t end = std::clock();
	double durationInMicroseconds = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC; // Calculate duration in microseconds
	print_main(main);
	std::cout << "Sorting took " << durationInMicroseconds << " microseconds." << std::endl;
	std::cout << (isSorted(main) ? "SORTED!!" : "WRONGGGGGGGG!") << std::endl;
}


