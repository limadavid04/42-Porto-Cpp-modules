#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;
class Form {
	public:
		Form();
		Form(const Form & cpy);
		Form & operator=(const Form &src);
		~Form();

		Form(const std::string &name, int signGrade, int execGrade);
		void beSigned(const Bureaucrat &b);
		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
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
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream & operator<<(std::ostream &out, const Form &form);

#endif
