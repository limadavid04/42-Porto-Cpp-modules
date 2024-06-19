#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#include <string>
class Intern {
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
		AForm* makeRobotomyForm(std::string target);
		AForm* makePresidentialForm(std::string target);
		AForm* makeShrubberyForm(std::string target);
		AForm *makeForm(std::string name, std::string target);
	private:
		static std::string _form_names[3];
		static AForm * (Intern::*p[3])(std::string target);
};

#endif
