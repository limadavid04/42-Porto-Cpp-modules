#include "Weapon.hpp"

void Weapon::setType(const std::string &type)
{
	_type = type;
}

const std::string &Weapon::getType() const
{
	return _type;
}
