#include "Dog.hpp"
#include <iostream>
#include "Brain.hpp"
Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}
Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = cpy;
}
Dog & Dog::operator=( const Dog & src)
{
	if (this != &src)
	{
		type = src.type;
		delete _brain;
		_brain = new Brain(*src._brain);
	}
	return (*this);
}
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "RUFF RUFF RUFF..." << std::endl;
}

