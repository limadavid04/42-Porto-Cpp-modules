#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
{
	// std::cout << "Default Cure constructor called" <<std::endl;
	_type = "cure";
}

Cure::Cure(Cure const &cpy) : AMateria(cpy)
{
	// std::cout << "Cure copy constructor called" <<std::endl;

}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" <<std::endl;
}

Cure const & Cure::operator=(Cure const &src)
{
	(void)src;
	_type = "cure";
	return *this;
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() <<"'s wounds *" <<std::endl;
}

AMateria* Cure::clone() const {
	return (new Cure());
}
