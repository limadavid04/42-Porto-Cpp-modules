#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
	public:
		HumanB(const std::string &name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon &weapon);
	private:
		std::string _name;
		Weapon *_weapon;
};
#endif
