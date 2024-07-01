#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
int main()
{
	MutantStack<int, std::vector<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "------" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int, std::vector<int> > s(mstack);
	return 0;
}
