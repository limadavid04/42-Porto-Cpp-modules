#ifndef PRESIDENTIALPARDON_HPP
#define PRESIDENTIALPARDON_HPP

#include "AForm.hpp"
#include <string.h>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm & cpy);
		PresidentialPardonForm & operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);
		void action() const;
	private:
		std::string _target;
};
#endif

