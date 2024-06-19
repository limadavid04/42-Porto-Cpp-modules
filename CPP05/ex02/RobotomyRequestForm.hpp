#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm & cpy);
		RobotomyRequestForm & operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		void execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

#endif
