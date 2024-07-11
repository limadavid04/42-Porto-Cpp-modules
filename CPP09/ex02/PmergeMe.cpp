#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cerrno>
#include <climits>
bool compare(std::pair<int, int> &a, std::pair<int, int> &b)
{
	return a.second < b.second;
}
unsigned long getNextJacobstal(unsigned long prev, unsigned long prevPrev) {
	return prev + 2 * prevPrev;
}

bool isSorted(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size() - 1; ++i) {
		if (vec[i] > vec[i + 1]) {
			return false;
		}
	}
	return true;
}
bool isSorted(const std::deque<int>& deq) {
	for (size_t i = 0; i < deq.size() - 1; ++i) {
		if (deq[i] > deq[i + 1]) {
			return false;
		}
	}
	return true;
}
template<typename Container>
void print_container(const Container& container) {
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
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

PmergeMe::PmergeMe() : _vec_time(0), _deq_time(0) {};
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe & cpy) {
	(void)cpy;
};
const PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	(void)src;
	return *this;
};

void PmergeMe::parse_input(int argc, char **argv) {

	if (argc == 1)
		throw std::runtime_error("Error");
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				throw std::runtime_error("Error");
		}
		char* end;
		long number = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || errno == ERANGE || number > INT_MAX || number < INT_MIN) {
			throw std::runtime_error("Error");
		}
		_vec.push_back(static_cast<int>(number));
		_deq.push_back(static_cast<int>(number));
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

void make_pairs(std::deque<int> deq, std::deque<std::pair<int, int > > &pairs)
{

	size_t sizeForSorting = deq.size() - (deq.size() % 2);

	for (size_t i = 0 ; i < sizeForSorting - 1; i+=2)
	{
		if(deq[i] > deq[i + 1])
			std::swap(deq[i], deq[i + 1]);
		pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
	}
	if (deq.size() != sizeForSorting)
		pairs.push_back(std::make_pair(deq[deq.size() - 1], (deq.size() / 2) + 1));
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
void fill_vectors(std::deque<int> &main, std::deque<std::pair<int, size_t > >&pending, std::deque<std::pair<int, int> > &pairs, int deq_size)
{
	std::deque<std::pair<int, int> >::iterator final_pos =  pairs.end() - (deq_size % 2);
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != final_pos; it++)
	{
		main.push_back(it->second);
		pending.push_back(std::make_pair(it->first, main.size())); //store the inital b order
	}
	if (final_pos == (--pairs.end()))
		pending.push_back(std::make_pair((--pairs.end())->first, (--pairs.end())->second));
	main.insert(main.begin(), pending.begin()->first);
	pending.erase(pending.begin());
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

void get_Jacobstal_insertion_list(const std::deque<std::pair<int, size_t> > &pending, std::deque<std::pair<int , size_t> > &insert_list , int pending_lst_size)
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
void insert_list_in_main(std::deque<std::pair<int , size_t> > &insert_list, std::deque<int> &main, size_t a_size)
{
	std::deque<int>::iterator pos;
	for (std::deque<std::pair<int, size_t> >::iterator it = insert_list.begin(); it != insert_list.end(); it++)
	{
		if (it->second >= a_size)
			pos = binary_search_insert_position(main.begin(), main.end(), it->first);
		else
			pos = binary_search_insert_position(main.begin(), main.end() - (a_size - it->second+1), it->first);
		main.insert(pos, it->first);
	}
}

std::deque<int> PmergeMe::fordJohnson_sort_deq()
{
	std::deque<std::pair<int, int> >pairs;
	std::deque<int> main;
	std::deque<std::pair<int, size_t> > pending;
	std::deque<std::pair<int , size_t> > insert_list;

	std::clock_t start = std::clock();
	if (_deq.size() == 1)
		return _deq;
	make_pairs(_deq, pairs);
	std::sort(pairs.begin(), (_deq.size() % 2 == 0 ? pairs.end(): --pairs.end()), compare);
	fill_vectors(main, pending, pairs, _deq.size());
	get_Jacobstal_insertion_list(pending, insert_list , ( _deq.size() / 2) + (_deq.size() % 2));
	insert_list_in_main(insert_list, main, _deq.size()/2);
	std::clock_t end = std::clock();
	_deq_time = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC; // Calculate duration in microseconds
	return main;
}
std::vector<int> PmergeMe::fordJohnson_sort_vec()
{
	std::vector<std::pair<int, int> >pairs;
	std::vector<int> main;
	std::vector<std::pair<int, size_t> > pending;
	std::vector<std::pair<int , size_t> > insert_list;

	std::clock_t start = std::clock();
	if (_vec.size() == 1)
		return _vec;
	make_pairs(_vec, pairs);
	std::sort(pairs.begin(), (_vec.size() % 2 == 0 ? pairs.end(): --pairs.end()), compare);
	fill_vectors(main, pending, pairs, _vec.size());
	get_Jacobstal_insertion_list(pending, insert_list , ( _vec.size() / 2) + (_vec.size() % 2));
	insert_list_in_main(insert_list, main, _vec.size()/2);
	std::clock_t end = std::clock();
	_vec_time = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC; // Calculate duration in microseconds
	return main;
}

void PmergeMe::fordJohnson_sort()
{
	std::cout << "Before:  ";
	print_container(_vec);
	std::cout << "After:  ";
	print_container(fordJohnson_sort_vec());
	fordJohnson_sort_deq();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << _vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << _deq_time << " us" << std::endl;

}


