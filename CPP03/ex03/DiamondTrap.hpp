#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public FragTrap , public ScavTrap {
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &cpy);
		~DiamondTrap();
		DiamondTrap & operator=( const DiamondTrap & src);

		DiamondTrap(const std::string &name);
		void whoAmI();
		using ScavTrap::attack;
	private:
		std::string _name;
};
#endif
