
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest-form",72, 45), _target("default") {
	// Initialize _target or other members if needed
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & cpy) : AForm(cpy){
	// Copy _target or other members if needed
	_target = cpy._target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// Clean up if needed
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest-form",72, 45), _target(target) {
	// Initialize other members if needed
}

void RobotomyRequestForm::action() const {
	// Implement the execution logic
	std::cout << "Drilling Noises..." << std::endl;
	if (rand() % 2) {
		std::cout << _target <<" has been robotomized successfully" << std::endl;
	} else
		std::cout << "Robotomy failed." << std::endl;
}
