#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat B("david", 150);
	Form F("form_1", 4, 2);
	std::cout << B << std::endl <<std::endl;
	std::cout << F << std::endl<<std::endl;
	B.signForm(F);
	std::cout << B << std::endl<<std::endl;
	std::cout << F << std::endl<<std::endl;
	B.incrementGrade(149);
	std::cout << B << std::endl<<std::endl;
	B.signForm(F);
	std::cout << F << std::endl<<std::endl;
	return 0;
}
