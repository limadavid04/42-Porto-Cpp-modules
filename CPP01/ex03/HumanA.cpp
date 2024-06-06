
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(Weapon weapon) : _weapon(weapon){}

void HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
