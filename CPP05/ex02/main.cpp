#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat B("david", 150);
	ShrubberyCreationForm S("David");
	RobotomyRequestForm R("joao");
	PresidentialPardonForm P("Trump");
	std::cout << B << std::endl <<std::endl;
	std::cout << R << std::endl<<std::endl;
	std::cout << S << std::endl<<std::endl;
	std::cout << P<< std::endl<<std::endl;

// Grade is too low
	B.signForm(S);
	std::cout << std::endl;
//Increment Grade
	B.incrementGrade(149);
	B.signForm(S);
	std::cout << std::endl;
	B.executeForm(S);
	std::cout << std::endl;

	B.executeForm(R);
	std::cout << std::endl;
	B.signForm(R);
	std::cout << std::endl;

	B.executeForm(R);
	std::cout << std::endl;
	B.signForm(P);
	std::cout << std::endl;
	B.executeForm(P);
	return 0;
}
