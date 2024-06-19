#include "AForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("default-Aform"), _isSigned(false), _signGrade(0), _execGrade(0) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm & cpy) : _name(cpy.getName()) , _isSigned(cpy.getIsSigned()), _signGrade(cpy.getSignGrade()), _execGrade(cpy.getExecGrade()) {
	std::cout << "AForm copy constructor called" << std::endl;
}
AForm & AForm::operator=(const AForm &src) {
	if (this != &src)
		_isSigned = src.getIsSigned();
	return (*this);
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	std::cout << "AForm Param constructor called" << std::endl;
	try {
		if (signGrade > 150)
			throw AForm::GradeTooLowException();
		else if (signGrade < 1)
			throw AForm::GradeTooHighException();
	} catch (const std::exception& e) {
		std::cerr << "Exception: Sign Grade: " << e.what() << std::endl;
	}
	try {
		if (execGrade > 150)
			throw AForm::GradeTooLowException();
		else if (execGrade < 1)
			throw AForm::GradeTooHighException();
	} catch (const std::exception& e) {
		std::cerr << "Exception: Exec Grade: " << e.what() << std::endl;
	}
}

AForm::~AForm() {
	std::cout << "AForm Desctructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecutionRequirements(Bureaucrat const & executor) const {
	if (getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
}

const std::string &AForm::getName() const {
	return _name;
}
bool AForm::getIsSigned() const {
	return _isSigned;
}
int AForm::getSignGrade() const {
	return _signGrade;
}
int AForm::getExecGrade() const {
	return _execGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}
const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}
const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}
std::ostream & operator<<(std::ostream &out, const AForm &AForm)
{
	out << "Form: " << AForm.getName()  << std::endl ;
	out << "Form signed ?: " << AForm.getIsSigned() << std::endl;
	out << "Form sign Grade: " << AForm.getSignGrade() << std::endl;
	out << "Form exec Grade: " << AForm.getExecGrade();
	return out;
}

