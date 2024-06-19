#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137), _target("default") {
	// Initialize _target or other members if needed
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & cpy) : AForm(cpy) {
	// Copy _target or other members if needed
	_target = cpy._target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		// Assign _target or other members if needed
		_target = src._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// Clean up if needed
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145,137), _target(target) {
	// Initialize other members if needed
}

void ShrubberyCreationForm::action() const {
	 std::ofstream file((_target + "_shrubbery").c_str());

	if (!file) {
		std::cerr << "Unable to open file for writing\n";
		return;
	}
	file << "    ^    "	<< "     *    \n"
		<< "   ^^^   "	<< "    ***   \n"
		<< "  ^^^^^  "	<< "   *****  \n"
		<< " ^^^^^^^ "	<< "  ******* \n"
		<< "^^^^^^^^^"	<< " *********\n"
		<< "    |    "	<< "     |    \n";



	file.close();
}

