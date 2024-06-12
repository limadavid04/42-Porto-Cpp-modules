#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(const FragTrap &cpy);
		~FragTrap();
		FragTrap & operator=( const FragTrap & src);

		FragTrap(const std::string &name);

		void attack(const std::string& target);
		void highFivesGuys(void);
		unsigned int getHitPoints() const;
		unsigned int getAttackDamage() const;
};
#endif
