#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "ideas...";
}
Brain::Brain(const Brain &cpy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = cpy;
}
Brain & Brain::operator=( const Brain & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
