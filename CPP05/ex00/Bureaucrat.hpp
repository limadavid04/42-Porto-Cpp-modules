#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>
class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat & cpy);
		Bureaucrat & operator=(const Bureaucrat &src);
		~Bureaucrat();


		Bureaucrat(const std::string &name, int grade);
		int getGrade() const;
		const std::string &getName() const;

		void incrementGrade(int value);
		void decrementGrade(int value);
		void checkGrade(int grade);
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
		int		_grade;
};

std::ostream & operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

