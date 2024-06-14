#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
{
	std::cout << "Default Ice constructor called" <<std::endl;
	_type = "ice";
}

Ice::Ice(Ice const &cpy)
{
	std::cout << "Ice copy constructor called" <<std::endl;
	*this = cpy;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" <<std::endl;
}

Ice const & Ice::operator=(Ice const &src)
{
	_type = "ice";
	return *this;
}


std::string const & Ice::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	// Implementation of the use() function
}

AMateria* Ice::clone() const {
	// Implementation of the clone() function
	// Replace with the actual implementation
}
