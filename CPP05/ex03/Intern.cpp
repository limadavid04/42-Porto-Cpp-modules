#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

std::string Intern::_form_names[3]= {
	"robotomy request",
	"shrubbery creation",
	"presidential pardon"
};

AForm* (Intern::*Intern::p[3])(std::string target) = {
	&Intern::makeRobotomyForm,
	&Intern::makeShrubberyForm,
	&Intern::makePresidentialForm
};

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}
Intern::~Intern() {

}
Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return (*this);
}
AForm* Intern::makeRobotomyForm(std::string target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::makePresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}
AForm* Intern::makeShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}
AForm *Intern::makeForm(std::string name, std::string target) {
	for (int i = 0; i < 3; i++)
		if (name == _form_names[i])
			return (this->*p[i])(target);
	std::cout << "There's no " << name << "form available" << std::endl;
	return (NULL);
}
