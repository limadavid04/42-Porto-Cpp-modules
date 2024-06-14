#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

unsigned int const FragTrap::_frag_hit_points  = 100;
unsigned int const FragTrap::_frag_attack_damage = 30;
// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
	// _name = "Default";
	_hit_points = _frag_hit_points;
	_energy_points = 100;
	_attack_damage = _frag_attack_damage;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap copy constructor  called" << std::endl;
	*this = cpy;
}

// Assignment operator
FragTrap & FragTrap::operator=(const FragTrap & src)
{
	std::cout << "FragTrap Assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	return *this;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "Parameterized FragTrap constructor called" << std::endl;
	// _name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

void FragTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0) {
		std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
	else if (!(_hit_points > 0))
		std::cout << "FragTrap " << _name << " cannot attack because it has 0 hit points" << std::endl;
	else if (!(_energy_points > 0))
			std::cout << "FragTrap " << _name << " cannot attack because it has 0 energy points" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout <<"FragTrap "<< _name <<" highFivesGuys!!" << std::endl;
}

