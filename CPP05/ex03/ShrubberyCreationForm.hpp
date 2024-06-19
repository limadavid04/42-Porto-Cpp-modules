#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm & cpy);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		void action() const;
	private:
		std::string _target;
};
#endif
