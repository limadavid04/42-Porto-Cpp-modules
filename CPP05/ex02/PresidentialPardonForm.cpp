#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25, 5), _target("default") {
	// Initialize _target or other members if needed
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & cpy) : AForm(cpy) {
	// Copy _target or other members if needed
	_target = cpy._target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		// Assign _target or other members if needed
		_target = src._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// Clean up if needed
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25, 5), _target(target) {
	// Initialize other members if needed
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
