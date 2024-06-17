#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
{
	// std::cout << "Default Ice constructor called" <<std::endl;
	_type = "ice";
}

Ice::Ice(Ice const &cpy) : AMateria(cpy)
{
	// std::cout << "Ice copy constructor called" <<std::endl;

}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" <<std::endl;
}

Ice const & Ice::operator=(Ice const &src)
{
	(void)src;
	_type = "ice";
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout <<"* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	return (new Ice());
}
