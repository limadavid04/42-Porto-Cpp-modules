
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name) {
	_weapon = new Weapon("No Weapon");
}

HumanB::~HumanB() {
}
void HumanB::attack() const
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	delete _weapon;
	_weapon = &weapon;
}
