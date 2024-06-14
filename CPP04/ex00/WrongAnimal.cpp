#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = cpy;
}
WrongAnimal & WrongAnimal::operator=( const WrongAnimal & src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;

}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Noise ..." << std::endl;
}

const std::string & WrongAnimal::getType() const
{
	return (type);
}
