#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() :_name("default"), _grade(0){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat & cpy) : _name(cpy.getName()) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
	{
		_grade = src.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat Param constructor called" << std::endl;
	try {
		checkGrade(grade);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Desctructor called" << std::endl;
}

int Bureaucrat::getGrade() const {
	return _grade;
}
const std::string & Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::checkGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::incrementGrade(int value) {
	try {
		if ((_grade - value) < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade -= value;
	} catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(int value) {
	try {
		if ((_grade + value) > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade += value;
	} catch (Bureaucrat::GradeTooLowException &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
	}
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream & operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
