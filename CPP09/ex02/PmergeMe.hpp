#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <list>
class PmergeME {
	private:
		std::vector<int> _vec;
		std::list<int> _lst;
	public:
		PmergeME();
		void parse_input(int argc, char** argv);
		void merge_insert_vec();
};
#endif
