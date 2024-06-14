
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	_name = "default_diamond";
	_hit_points = _frag_hit_points;
	_energy_points = _scav_energy_points;
	_attack_damage = _frag_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), FragTrap(cpy), ScavTrap(cpy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap & src)
{
	std::cout << "Diamond Assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	if (this != &src)
		_name = src._name;
	return *this;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_trap")
{
	std::cout << "Parameterized DiamondTrap constructor called" << std::endl;
	_name = name;
	_hit_points = _frag_hit_points;
	_energy_points = _scav_energy_points;
	_attack_damage = _frag_attack_damage;
}

void DiamondTrap::whoAmI() {
	std::cout << "My DiamondTrap name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}
