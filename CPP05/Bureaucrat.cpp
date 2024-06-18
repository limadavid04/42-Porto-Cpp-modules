#include "Bureaucrat.hpp"
#include "iostream"

Bureaucrat::Bureaucrat() {

}
Bureaucrat::Bureaucrat(const Bureaucrat & cpy) {

}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src) {

}
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name) {

}

Bureaucrat::~Bureaucrat() {

}

const unsigned int Bureaucrat::getGrade() const {
	return _grade;
}
const std::string Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incrementGrade(unsigned int value) {
	if ((_grade - value) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= value;
}

void Bureaucrat::decrementGrade(unsigned int value) {
	if ((_grade + value) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += value;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream & operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out <<
}
