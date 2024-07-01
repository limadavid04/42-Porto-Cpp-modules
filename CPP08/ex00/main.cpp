#include "easyfind.hpp"
#include <vector>
#include <list>
int main()
{//change from set to vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::list<char> lst;
	lst.push_back('a');
	lst.push_back('v');
	lst.push_back('k');
	lst.push_back('}');
	lst.push_back('i');
	lst.push_back('R');
	easyfind(vec, 3);
	easyfind<std::list<char> >(lst, 'k');
	return (0);
}
