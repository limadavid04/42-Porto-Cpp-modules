#include "Zombie.hpp"
#include <iostream>


Zombie::~Zombie()
{
	std::cout << _name << ": was destroyed" << std::endl;
}
void Zombie::announce (void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
	_name = name;
}
