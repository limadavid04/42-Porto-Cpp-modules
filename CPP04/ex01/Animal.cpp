#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(const Animal &cpy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = cpy;
}
Animal & Animal::operator=( const Animal & src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;

}
void Animal::makeSound() const
{
	std::cout << "Animal Noise ..." << std::endl;
}

const std::string & Animal::getType() const
{
	return (type);
}
