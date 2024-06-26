#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
}
Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = cpy;
}
Dog & Dog::operator=( const Dog & src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "RUFF RUFF RUFF..." << std::endl;
}

