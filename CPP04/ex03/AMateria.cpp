#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	// std::cout << "Default AAmateria constructor called" <<std::endl;
}

AMateria::AMateria(AMateria const &cpy)
{
	// std::cout << "AAmateria copy constructor called" <<std::endl;
	*this = cpy;
}

AMateria::~AMateria()
{
	// std::cout << "Amateria destructor called" <<std::endl;
}

AMateria const & AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		_type = src._type;
	return *this;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "Param Amateria constructor called" <<std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}

// void AMateria::use(ICharacter& target) {
// 	if (_type == "ice")
//  		std::cout <<"* shoots an ice bolt at " << target.getName() << " *" << std::endl;
// 	else if (_type == "cure")
// 		std::cout << "* heals "<< target.getName() <<"'s wounds *" <<std::endl;
// }


