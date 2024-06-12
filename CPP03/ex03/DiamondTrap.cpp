
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_trap")
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	std::cout<< std::endl << "/*---------Ignore-----------*/" << std::endl;
	FragTrap frag;
	ScavTrap scav;
	std::cout << "/*---------Ignore-----------*/" << std::endl << std::endl;
	_name = "default_diamondTrap";
	_hit_points = frag.getHitPoints();
	_energy_points = scav.getEnergyPoints();
	_attack_damage = frag.getAttackDamage();

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

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_trap"), FragTrap(name), ScavTrap(name)
{
	std::cout << "Parameterized DiamondTrap constructor called" << std::endl;
	std::cout <<std::endl <<"/*---------Ignore-----------*/" << std::endl;
	FragTrap frag;
	ScavTrap scav;
	std::cout << "/*---------Ignore-----------*/" << std::endl << std::endl;
	_name = name;
	_hit_points = frag.getHitPoints();
	_energy_points = scav.getEnergyPoints();
	_attack_damage = frag.getAttackDamage();
}

void DiamondTrap::whoAmI() {
	std::cout << "My DiamondTrap name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}
