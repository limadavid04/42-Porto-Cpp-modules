#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cpy;
}
WrongCat & WrongCat::operator=( const WrongCat & src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;

}
void WrongCat::makeSound() const
{
	std::cout << "WrongMIAU WrongMIAU WrongMIAU ..." << std::endl;
}

