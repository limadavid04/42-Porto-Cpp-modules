#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>



// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	// _name = "Default";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap copy constructor  called" << std::endl;
	*this = cpy;
}

// Assignment operator
ScavTrap & ScavTrap::operator=(const ScavTrap & src)
{
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{

	std::cout << "Parameterized ScavTrap constructor called" << std::endl;
	// _name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;

}

void ScavTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
	else if (!(_hit_points > 0))
		std::cout << "ScavTrap " << _name << " cannot attack because it has 0 hit points" << std::endl;
	else if (!(_energy_points > 0))
			std::cout << "ScavTrap " << _name << " cannot attack because it has 0 energy points" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gateKeeper mode" << std::endl;
}
unsigned int ScavTrap::getEnergyPoints() const
{
	return (_energy_points);
}
