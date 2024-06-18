#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>
class Bureaucrat {

	Bureaucrat();
	Bureaucrat(const Bureaucrat & cpy);
	Bureaucrat & operator=(const Bureaucrat &src);
	~Bureaucrat();


	Bureaucrat(const std::string &name, unsigned int grade);
	const unsigned int getGrade() const;
	const std::string getName() const;

	void incrementGrade(unsigned int value);
	void decrementGrade(unsigned int value);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream & operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

