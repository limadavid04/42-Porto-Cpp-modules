#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public FragTrap , public ScavTrap {
	public:
		DiamondTrap(const std::string &name);
	private:
		std::string _name;
};
#endif
