#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
{
	std::cout << "Default Cure constructor called" <<std::endl;
	_type = "Cure";
}

Cure::Cure(Cure const &cpy)
{
	std::cout << "Cure copy constructor called" <<std::endl;
	*this = cpy;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" <<std::endl;
}

Cure const & Cure::operator=(Cure const &src)
{
	_type = "Cure";
	return *this;
}


std::string const & Cure::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	// Implementation of the use() function
}

AMateria* Cure::clone() const {
	// Implementation of the clone() function
	// Replace with the actual implementation
}
