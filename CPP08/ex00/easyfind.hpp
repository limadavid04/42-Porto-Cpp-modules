#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iterator>
#include <iostream>
#include <algorithm>
template <typename Cont>

typename Cont::iterator easyfind(Cont &container, int target)
{
	typename Cont::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		return (std::cout << target <<" not found." <<std::endl, container.end());
	return (std::cout << "found "<< target<< " at index " << std::distance(container.begin(), it) << std::endl, it);
}
#endif
