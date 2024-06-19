#include "Form.hpp"

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("default-form"), _isSigned(false), _signGrade(0), _execGrade(0) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form & cpy) : _name(cpy.getName()) , _isSigned(cpy.getIsSigned()), _signGrade(cpy.getSignGrade()), _execGrade(cpy.getExecGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}
Form & Form::operator=(const Form &src) {
	if (this != &src)
		_isSigned = src.getIsSigned();
	return (*this);
}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	std::cout << "Form Param constructor called" << std::endl;
	try {
		if (signGrade > 150)
			throw Form::GradeTooLowException();
		else if (signGrade < 1)
			throw Form::GradeTooHighException();
	} catch (const std::exception& e) {
		std::cerr << "Exception: Sign Grade: " << e.what() << std::endl;
	}
	try {
		if (execGrade > 150)
			throw Form::GradeTooLowException();
		else if (execGrade < 1)
			throw Form::GradeTooHighException();
	} catch (const std::exception& e) {
		std::cerr << "Exception: Exec Grade: " << e.what() << std::endl;
	}
}

Form::~Form() {
	std::cout << "Form Desctructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}


const std::string &Form::getName() const {
	return _name;
}
bool Form::getIsSigned() const {
	return _isSigned;
}
int Form::getSignGrade() const {
	return _signGrade;
}
int Form::getExecGrade() const {
	return _execGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}
const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream & operator<<(std::ostream &out, const Form &Form)
{
	out << "Form: " << Form.getName()  << std::endl ;
	out << "Form signed ?: " << Form.getIsSigned() << std::endl;
	out << "Form sign Grade: " << Form.getSignGrade() << std::endl;
	out << "Form exec Grade: " << Form.getExecGrade();
	return out;
}

