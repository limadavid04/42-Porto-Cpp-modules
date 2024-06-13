#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}
Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cpy;
}
Cat & Cat::operator=( const Cat & src)
{
	if (this != &src)
	{
		type = src.type;
		delete _brain;
		_brain = new Brain(*src._brain);
	}
	return (*this);
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;

}
void Cat::makeSound() const
{
	std::cout << "MIAU MIAU MIAU ..." << std::endl;
}

