#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;
class AForm {
	public:
		AForm();
		AForm(const AForm & cpy);
		AForm & operator=(const AForm &src);
		virtual ~AForm();

		AForm(const std::string &name, int signGrade, int execGrade);
		void beSigned(const Bureaucrat &b);
		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream & operator<<(std::ostream &out, const AForm &Aform);

#endif
