#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat B("david", 150);
	std::cout << B << std::endl;
	B.incrementGrade(100);
	std::cout << B << std::endl;
	B.decrementGrade(20);
	std::cout << B << std::endl;
	return 0;
}
