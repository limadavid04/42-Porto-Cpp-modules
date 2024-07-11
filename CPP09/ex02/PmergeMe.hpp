#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		double _vec_time;
		double _deq_time;
		std::vector<int> fordJohnson_sort_vec();
		std::deque<int> fordJohnson_sort_deq();
		PmergeMe(const PmergeMe & cpy);
		const PmergeMe & operator=(const PmergeMe & src);
	public:
		PmergeMe();
		~PmergeMe();
		void parse_input(int argc, char** argv);
		void fordJohnson_sort();
};
#endif
