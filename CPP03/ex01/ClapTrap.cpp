#include "ClapTrap.hpp"
#include <iostream>
// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = cpy;
}

// Assignment operator
ClapTrap & ClapTrap::operator=(const ClapTrap & src)
{
	if (this != &src) {
		_name = src._name;
		_hit_points = src._hit_points;
		_energy_points = src._energy_points;
		_attack_damage = src._attack_damage;
	}
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Parameterized ClapTrap constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
	else if (!(_hit_points > 0))
		std::cout << "ClapTrap " << _name << " cannot attack because it has 0 hit points" << std::endl;
	else if (!(_energy_points > 0))
			std::cout << "ClapTrap " << _name << " cannot attack because it has 0 energy points" << std::endl;

}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0 && _hit_points == 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else if (amount > 0)
	{
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage " << std::endl;
		if ((int)(_hit_points - amount) <= 0)
		{
			_hit_points = 0;
			std::cout << "ClapTrap " <<_name << " is dead" << std::endl;
		}
		else
			_hit_points -= amount;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0) {
		std::cout << "ClapTrap " << _name << " got " << amount << " hit points back"<< std::endl;
		_hit_points += amount;
		_energy_points--;
	}
	else if (!(_hit_points > 0))
		std::cout << "ClapTrap " <<_name << " cannot repair itself because it has 0 hit points" << std::endl;
	else if (!(_energy_points > 0))
		std::cout << "ClapTrap " << _name << " cannot repair itself because it has 0 energy points" << std::endl;

}
