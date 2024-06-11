#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &cpy);
		~ScavTrap();
		ScavTrap & operator=( const ScavTrap & src);

		ScavTrap(const std::string &name);

		void attack(const std::string& target);
		void guardGate();
};
#endif
